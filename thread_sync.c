/*
	gcc -o thread_basics thread_basics.c -lpthread
	./thread_basics t1 t2 t3 t4
*/

#include <pthread.h>
#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <errno.h>
#include <ctype.h>

#define handle_error_en(en, msg) \
	do { errno = en; perror(msg); exit(EXIT_FAILURE); } while (0)

#define handle_error(msg) \
	do { perror(msg); exit(EXIT_FAILURE); } while (0)

struct thread_info {			/* Used as argument to reader_thread() */
	pthread_t thread_id;		/* ID returned by pthread_create() */
	int       thread_num;		/* Application-defined thread # */
	char     *argv_string;		/* From command-line argument */
};

int critical_section_data;
pthread_mutex_t lock;

/* Thread start function: display address near top of our stack,
   and return upper-cased copy of argv_string */

static void *reader_thread(void *arg)
{
	struct thread_info *tinfo = arg;
	char *uargv, *p;

	printf("Reader Thread %d:   argv_string=%s\n",
			tinfo->thread_num, tinfo->argv_string);

	uargv = strdup(tinfo->argv_string);
	if (uargv == NULL)
		handle_error("strdup");

	for (p = uargv; *p != '\0'; p++)
		*p = toupper(*p);

//	critical_section_data++;
	while(1) {
		pthread_mutex_lock(&lock);
		sleep(1);
		printf("Reader Thread %d: critical section data=%d\n",
			tinfo->thread_num, critical_section_data);
		pthread_mutex_unlock(&lock);
		sleep(1);
	}
	return uargv;
}

/*
	Writer thread;
*/

static void * writer_thread(void *arg)
{
	struct thread_info *tinfo = arg;
	char *uargv, *p;

	printf("Writer Thread %d:   argv_string=%s\n",
			tinfo->thread_num, tinfo->argv_string);

	uargv = strdup(tinfo->argv_string);
	if (uargv == NULL)
		handle_error("strdup");

	for (p = uargv; *p != '\0'; p++)
		*p = toupper(*p);

	while(1) {
		pthread_mutex_lock(&lock);
		critical_section_data++;
		printf("Writer Thread before %d: critical data=%d\n",
			tinfo->thread_num, critical_section_data);
		sleep(1);
		printf("Writer Thread after  %d: critical data=%d\n",
			tinfo->thread_num, critical_section_data);
		pthread_mutex_unlock(&lock);
		sleep(1);
	}
	return uargv;
}
int main(int argc, char *argv[])
{
	int s, tnum, opt, num_threads;
	struct thread_info *tinfo;
	pthread_attr_t attr;
	int stack_size;
	void *res;

	/* The "-s" option specifies a stack size for our threads */

	stack_size = -1;
	while ((opt = getopt(argc, argv, "s:")) != -1) {
		switch (opt) {
			case 's':
				stack_size = strtoul(optarg, NULL, 0);
				break;

			default:
				fprintf(stderr, "Usage: %s [-s stack-size] arg...\n",
						argv[0]);
				exit(EXIT_FAILURE);
		}
	}

	if (pthread_mutex_init(&lock, NULL) != 0)
	{
		printf("\n mutex init failed\n");
		return 1;
	}
	num_threads = argc - optind;

	/* Initialize thread creation attributes */

	s = pthread_attr_init(&attr);
	if (s != 0)
		handle_error_en(s, "pthread_attr_init");

	if (stack_size > 0) {
		s = pthread_attr_setstacksize(&attr, stack_size);
		if (s != 0)
			handle_error_en(s, "pthread_attr_setstacksize");
	}

	/* Allocate memory for pthread_create() arguments */

	tinfo = calloc(num_threads, sizeof(struct thread_info));
	if (tinfo == NULL)
		handle_error("calloc");

	/* Create one thread for each command-line argument */

	for (tnum = 0; tnum < num_threads; tnum++) {
		tinfo[tnum].thread_num = tnum + 1;
		tinfo[tnum].argv_string = argv[optind + tnum];

		/* The pthread_create() call stores the thread ID into
		   corresponding element of tinfo[] */

		if(tnum == 0) {
			s = pthread_create(&tinfo[tnum].thread_id, &attr,
						&writer_thread, &tinfo[tnum]);
		} else {
			s = pthread_create(&tinfo[tnum].thread_id, &attr,
						&reader_thread, &tinfo[tnum]);
		}
		if (s != 0)
			handle_error_en(s, "pthread_create");
	}


	/* Destroy the thread attributes object, since it is no
	   longer needed */

	s = pthread_attr_destroy(&attr);
	if (s != 0)
		handle_error_en(s, "pthread_attr_destroy");

	/* Now join with each thread, and display its returned value */

	for (tnum = 0; tnum < num_threads; tnum++) {
		s = pthread_join(tinfo[tnum].thread_id, &res);
		if (s != 0)
			handle_error_en(s, "pthread_join");

		printf("Joined with thread %d; returned value was %s\n",
				tinfo[tnum].thread_num, (char *) res);
		free(res);      /* Free memory allocated by thread */
	}
	pthread_mutex_destroy(&lock);
	free(tinfo);
	exit(EXIT_SUCCESS);
}


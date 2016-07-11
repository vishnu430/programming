/*
command: valgrind ./memory_leak --leak-check=full –show-reachable=yes
*/

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
main()
{

	char str[4];
	int *memptr = NULL;
	int index = 10;
	
	int s = 1;
	int *p=&s;

//	p[-2]=7;
//	s=p[-20];



	memptr = malloc(10);
	memptr[index] = 10;
	strcpy(str, "Hello");
	str[5] ='a';
	if(s < 2) {
		free(memptr);
		exit(0);
	}
	free(memptr);



	while(1);
}

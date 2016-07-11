#include <stdio.h>
int main()
{
	char (*ptrtochar)[4];
	char *arrptr[4];
	void *vptr;

	printf("sizeof int %lu\n", sizeof(int));
	printf("sizeof ptr to 4 chars %lu\n", sizeof(ptrtochar));
	printf("sizeof array of pointers %lu\n", sizeof(arrptr));
	printf("sizeof void pointers %lu\n", sizeof(vptr));


}

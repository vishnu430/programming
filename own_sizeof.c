#include <stdio.h>


#define  my_sizeof(sizeofvar) (char *)(&sizeofvar+1) - (char *)(&sizeofvar)
#define SIZEOF(e) ({ typeof(e) _; (void *)(&_+1) - (void *)(&_); })

int main()
{

	int var;

	printf("size of var %lu\n", my_sizeof(var));
	printf("size of int %lu\n", SIZEOF(int));
	printf("size of int %lu\n", SIZEOF(var));

}

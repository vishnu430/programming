#include <stdio.h>
int using_union(void)
{	
	union endian {
		int var;
		char ch[1];

	} chk_endianness = {.var=1};

	if ( chk_endianness.ch[0] == 1 ) {
		return 0;	// Little endian
	} else {
		return 1;	// Big endian
	}
}

int using_pointer(void)
{
	int var = 1;
	char *cptr =(char *)&var;
	if(*cptr) {
		return 0;	// Little endian
	} else {
		return 1;	// Big endian
	}
}

int main()
{
	int ret = -1;
	ret = using_pointer();
	ret ?printf("Big endian\n") : printf("Little endian\n");;
	ret = using_union();
	ret ?printf("Big endian\n") : printf("Little endian\n");;


}

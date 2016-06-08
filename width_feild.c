#include <stdio.h>
int main()
{

	int var1 = 10;
	int var2 = 20;
	int ret = 0;
	printf("test: %d\n", var1);
	ret = printf("%*c%*c", var1, '\r', var2, '\r');
	printf("ret: %d\n", ret);


}

#include <stdio.h>
int main()
{
	struct node {
		int a;
		int b;
		int c;
	};

	struct node s = {3, 5, 6};
	struct node *pt = &s;

	printf("5 is %d\n",*(++((int *)pt)) );

}



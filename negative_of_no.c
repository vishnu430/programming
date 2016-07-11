#include <stdio.h>

int main()
{

	int var = -3;
	int size = sizeof(int) * 8;
	int i;
	for(i = 1; i <= size; i++)
	{
		printf("%d",(((var >> (size - i)) & 1)?1:0));
		if(i%8 == 0)
			printf(" ");
	}

	printf("\n");
	printf("-1 >> 3: %d\n", -1 >> 3);
	printf("1 >> 3: %d\n", 1 >> 3);
}


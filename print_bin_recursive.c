#include<stdio.h>
void print_bin(unsigned int val)
{

	if(val > 0) {

		print_bin(val/2);
		printf("%d", val%2);
	}


}

int main()
{

	printf("4: ");
	print_bin(4);
	printf("\n");

	printf("5: ");
	print_bin(5);
	printf("\n");

	printf("6: ");
	print_bin(6);
	printf("\n");

	printf("8: ");
	print_bin(8);
	printf("\n");

	printf("13: ");
	print_bin(13);
	printf("\n");
}

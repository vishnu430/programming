#include <stdio.h>

extern int asm_add(int, int);
int main() {
	int c;
	c=asm_add(10,20);
	printf("ASM add result = %d\n", c);
	return 0;
}


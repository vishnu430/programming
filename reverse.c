#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Reverse the word based on start and end pointer
void reverse_word(char *p1, char *p2)
{
	char tmpchr;
	
	while(p1 < p2) {
		tmpchr = *p1;
		*p1 = *p2;
		*p2 = tmpchr;
		p1++;
		p2--;
	}

}

void reverse_str(char *str)
{
	char *p1 = NULL, *p2 = NULL;

	p1 = str;
	p2 = str;
	while (*p1 != '\0') {
		p2 = strchr(p1, ' ');			// searching for word completion
		if(p2 == NULL)
			p2 = p1 + strlen(p1);
		reverse_word(p1, p2-1);			// reverse the word
		if(*p2 != '\0')
			p1 = p2 + 1;			// moving p1 and p2 pointer to next word
		else 
			p1 = p2;

	}
}

int main(int argc, char *argv[])
{

	if(argc != 2) {
		printf("Syntax error: %s <string>\n", argv[0]);
		exit(0);
	}


	printf("Before: %s\n", argv[1]);
	reverse_str(argv[1]);
	printf("After : %s\n", argv[1]);

}


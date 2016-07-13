#include <stdio.h>
int parse_str(const char *str)
{

	int cnt = 0;
	int i;

	for(i=0; str[i]; i++) {

		if(str[i] == '(')
			cnt++;
		if(str[i] == ')')
			cnt--;
		if(cnt < 0)
			break;
	}

	return cnt;


}

int main()
{
	char *str1 = "() () ()";
	char *str2 = "( () )";
	char *str3 = ") () (";
	char *str4 = "() ) ()";
	char *str5 = "() ( ()";
	

	printf ("%d \t", parse_str(str1));
	parse_str(str1)?printf("Failed\n"):printf("Success\n");
	printf ("%d \t", parse_str(str2));
	parse_str(str2)?printf("Failed\n"):printf("Success\n");
	printf ("%d \t", parse_str(str3));
	parse_str(str3)?printf("Failed\n"):printf("Success\n");
	printf ("%d \t", parse_str(str4));
	parse_str(str4)?printf("Failed\n"):printf("Success\n");
	printf ("%d \t", parse_str(str5));
	parse_str(str5)?printf("Failed\n"):printf("Success\n");


}

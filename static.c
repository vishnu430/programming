#include <stdio.h>
call_main()
{

	int b = 10;
	static int a;
	a =b;
//	a=10;
	printf("a:%d\n",a);
	a++;
//	a = 20;
}

main()
{
	call_main();
	call_main();
	call_main();
	call_main();

	call_main();

}

#include <stdio.h>
int main(int argc,char **argv)
{
    register int i = 5;
    if (--i){
        printf("%p0 ", &i);
    }
}

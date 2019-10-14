#include <cstdio>

int main(void)
{
	int a,b;
	scanf("%d %d\n",&a,&b);
	int c = a-b;
	if(a-b > 0) printf(">\n");
	if(a-b == 0) printf("==\n");
	if(a-b < 0) printf("<\n");
}

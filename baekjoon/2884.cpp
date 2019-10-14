#include <cstdio>

int main(void)
{
	int a,b;
	scanf("%d %d", &a, &b);
	b -= 45;
	if(b < 0) {
		b += 60;
		a -= 1;
	}
	if(a < 0) {
		a += 24;
	}
	printf("%d %d\n", a, b);
}

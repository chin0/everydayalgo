#include <cstdio>

int main(void)
{
	long long n;
	scanf("%lld", &n);
	int cur = 1;
	int i = 1;
	while(n > cur) {
		cur += 6*i;
		i++;
	}
	printf("%d\n",i);
}

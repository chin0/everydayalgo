#include <cstdio>

int get_next(int n) {
	if(n < 10) {
		return n*10 + n;
	}
	return (n*10 % 100) + ((n/10 + n%10)%10);
}
int main(void)
{
	int i,n,cnt=0;
	scanf("%d", &i);
	n=i;
	while((i=get_next(i)) != n) cnt++;
	printf("%d\n",cnt+1);
}

	


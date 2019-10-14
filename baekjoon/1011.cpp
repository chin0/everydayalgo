#include <cstdio>

int main(void)
{
    long long int x,y;
    scanf("%lld %lld", &x, &y);
    long long int d = y-x-1;

    long long int i = 1;
    long long int s = 0;
    while(s < d) {
        s += i;
        i++;
    }
    printf("%lld\n",i);
}

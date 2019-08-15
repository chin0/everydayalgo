#include <cstdio>

long long fibo[1500001];

int mod = 1000000;

int main(void)
{
    long long n;
    scanf("%lld", &n);

    fibo[0] = 0;
    fibo[1] = 1;
    for(int i = 2; i <= 1500000; i++) {
        fibo[i] = (fibo[i-1] + fibo[i-2]) % mod;
    }
    printf("%lld\n",fibo[n % 1500000]);
}

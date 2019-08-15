#include <cstdio>

long long phi(long long n)
{
    long long ans = n;
    for(long long i = 2; i*i <= n; i++) {
        if(n % i == 0) {
            while(n % i == 0) {
                n /= i;
            }
            ans -= ans / i;
        }
    }
    if(n > 1)
        ans -= ans / n;
    return ans;
}

int main(void)
{
    long long n;
    scanf("%lld", &n);
    printf("%lld\n", phi(n));
}

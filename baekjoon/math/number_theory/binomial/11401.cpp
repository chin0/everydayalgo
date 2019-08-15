#include <cstdio>

long long mod = 1000000007;
long long pow(long long n, long long b)
{
    long long ans = 1;
    while(b > 0) {
        if((b&1) == 1){
            ans *= n;
            ans %= mod;
        }
        n *= n;
        n %= mod;
        b >>= 1;
    }
    return ans;
}

int main(void)
{
    long long n,k;
    scanf("%lld %lld", &n, &k);
    long long A = 1;
    long long B = 1;
    for(int i = 0; i < k; i++) {
        A *= (n-i);
        A %= mod;
    }
    for(int i = 1; i <= k; i++) {
        B *= i;
        B %= mod;
    }
    long long inv = pow(B,mod-2) % mod;
    long long ans = (A * inv) % mod;
    printf("%lld\n",ans);
}

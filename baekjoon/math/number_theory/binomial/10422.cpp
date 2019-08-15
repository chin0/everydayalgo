//대표적인 까탈란 수 문제.
#include <cstdio>

using namespace std;

long long dp[2501];
long long mod = 1000000007;
int main(void)
{
    int t,n;
    scanf("%d", &t);

    dp[0] = 1;
    for(int i = 1; i <= 2500; i++) {
        for(int j=0; j < i; j++) {
            dp[i] += dp[j]*dp[i-j-1];
            dp[i] %= mod;
        }
    }
    for(int i = 0; i < t; i++) {
        scanf("%d",&n);
        printf("%lld\n", (n%2) ? 0 : dp[n/2]);
    }
}

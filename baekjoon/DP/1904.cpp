#include <cstdio>

int dp[1000001];

int main(void)
{
    int n;
    scanf("%d", &n);

    dp[1] = 1;
    dp[2] = 2;
    for(int i = 3; i <=n; i++) {
        dp[i] = (dp[i-1] + dp[i-2]) % 15746;
    }
    printf("%d\n",dp[n]);
}

#include <stdio.h>

unsigned long long dp[91];

unsigned long long solve(int n) {
    dp[1] = 1;
    dp[2] = 1;
    for(int i = 3; i <= n; i++) {
        for(int j = 1; j < i-1; j++) {
            dp[i] += dp[j];
        }
        dp[i] += 1;
    }
    return dp[n];
}

int main(void) 
{
    int n;
    scanf("%d",&n);
    printf("%llu\n",solve(n));
}
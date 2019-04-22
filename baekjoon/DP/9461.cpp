#include <stdio.h>

typedef unsigned long long int ull;
ull dp[101];

ull solve(int n) 
{
    if (n == 0) return 0;
    if (n <= 3) return 1;
    if (n <= 5) return 2;
    if(dp[n] != 0) return dp[n];
    dp[n] = solve(n-1) + solve(n-5);
    return dp[n];
}
int main(void)
{
    int t,n;
    scanf("%d",&t);
    for(int i = 0; i < t; i++ ) {
        scanf("%d", &n);
        printf("%llu\n",solve(n));
    }
}
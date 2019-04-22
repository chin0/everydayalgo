#include <stdio.h>
#include <array>

using namespace std;

typedef unsigned long long int ull;
array<array<ull, 201>, 201 > dp;

ull solve(int n, int k) {
    if(k == 1) 
        return k;
    if(dp[n][k] != 0)
        return dp[n][k];
    dp[n][k] = 0;
    for(int i = 0; i <= n; i++) {
        dp[n][k] = (dp[n][k] + solve(n-i,k-1)) % 1000000000;
    }
    return dp[n][k];
}

int main(void) {
    int n,k;
    scanf("%d %d",&n, &k);
    printf("%llu\n", solve(n,k));
}
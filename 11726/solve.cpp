#include <cstdio>
#include <algorithm>

using namespace std;

int dp[1001];
int solve(int n) {
    dp[1] = 1;
    dp[2] = 2;
    for(int i = 3; i <= n; i++) {
        dp[i] = (dp[i-1] + dp[i-2]) % 10007;
    }
    return dp[n];
}
int main()
{
    int n;
    scanf("%d", &n);
    printf("%d\n", solve(n));
}
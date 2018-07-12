#include <cstdio>

using namespace std;

int dp[1001];
int f(int n) {
    dp[1] = 1;
    dp[2] = 3;

    for(int i = 3; i <= n; i++) 
        dp[i] = (dp[i-1] + 2 * dp[i-2]) % 10007;
    
    return dp[n];
}
int main(void) {
    int n;
    scanf("%d",&n);
    printf("%d\n",f(n));
}
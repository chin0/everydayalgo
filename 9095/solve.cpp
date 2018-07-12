#include <cstdio>

using namespace std;

int dp[12];
int f(int n) {
    dp[1] = 1;
    dp[2] = 2;
    dp[3] = 4;
    for(int i = 4; i <= n; i++) {
        dp[i] = dp[i-1] + dp[i-2] + dp[i-3];
    }
    return dp[n];
}

int main(void) {
    int n,m;
    scanf("%d", &m);
    for(int i = 0; i<m; i++) {
        scanf("%d", &n);
        printf("%d\n",f(n));
    }
}
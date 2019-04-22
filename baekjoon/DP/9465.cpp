#include <stdio.h>
#include <algorithm>

using namespace std;

int dp[2][100000];
int data[2][100000];

// 선택할수있는 경로를 생각하면 점화식은 자명함.
int solve(int n) {
    dp[0][0] = data[0][0];
    dp[1][0] = data[1][0];
    dp[1][1] = dp[0][0] + data[1][1];
    dp[0][1] = dp[1][0] + data[0][1];

    for(int i = 2; i < n; i++) {
        dp[0][i] = max(dp[1][i-1],dp[1][i-2]) + data[0][i];
        dp[1][i] = max(dp[0][i-1],dp[0][i-2]) + data[1][i];
    }
    return max(dp[0][n-1],dp[1][n-1]);
}

int main(void)
{
    int t;
    int n;
    scanf("%d",&t);
    for(int i = 0; i < t; i++) {
        scanf("%d",&n);
        for(int j = 0; j < 2; j++) {
            for(int k = 0; k < n; k++) {
                scanf("%d",&data[j][k]);
            }
        }
        printf("%d\n",solve(n));
    }
}
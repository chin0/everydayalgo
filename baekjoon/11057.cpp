#include <stdio.h>

int dp[1001][10];

int solve(int N) {
    for(int i = 0; i < 10; i++) {
        dp[1][i] = 1;
    }

    for(int i = 2; i <= N; i++) {
        dp[i][0] = 1;
        for(int j = 1; j < 10; j++) {
            for(int k = 0; k <= j; k++) {
                dp[i][j] = (dp[i][j] +  dp[i-1][k]) %10007;
            }
        }
    }
    int result =0;
    for(int i = 0; i < 10; i++) {
        result = (result + dp[N][i]) % 10007;
    }
    return result;
}

int main(void)
{
    int N;
    scanf("%d",&N);
    printf("%d\n",solve(N));
}
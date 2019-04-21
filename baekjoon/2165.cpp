#include <stdio.h>
#include <algorithm>
using namespace std;

int dp[10001]; //dp[n] -> n까지의 최대값.
int data[10001];

int solve(int n) 
{
    dp[1] = data[1];
    dp[2] = dp[1] + data[2];

    for(int i = 3; i <= n; i++) {
        dp[i] = max(dp[i-1],data[i] + dp[i-2]); //n번째 잔을 안마시는 경우 vs n-1번째 잔을 안마시는 경우
        dp[i] = max(dp[i], dp[i-3] + data[i] + data[i-1]); //n-2번째 잔을 안마셨을경우.
    }
    return dp[n];
}
int main(void)
{
    int n = 0;
    scanf("%d",&n);
    for(int i= 1; i <= n; i++) {
        scanf("%d",&data[i]);
    }
    printf("%d\n",solve(n));
}
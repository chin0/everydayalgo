#include <stdio.h>
#include <algorithm>

using namespace std;

int dp[100001];

//처음에는 단순히 j = isqrt(n)로 두고 j == i라면 dp[i] = 1
//아니라면  dp[i] = dp[i-j*j] + 1로 두고 하였으나, 12 = 3^2 + 1^2 + 1^2 + 1^2이외에
// 12 = 2^2 + 2^2 + 2^2라는 반례가 있었기에 걍 i이하의 제곱수를 전부다 체크해주는 방향으로 바꿨다.

int solve(int n) {
    dp[0] = 0;
    dp[1] = 1;
    dp[2] = 2;
    for(int i = 3; i <= n; i++) {
        dp[i] = i;
        for(int j = 1; j*j <= i; j++) {
            dp[i] = min(dp[i-j*j] + 1, dp[i]);
        }
    }
    return dp[n];
}
int main(void) {
    int n;
    scanf("%d",&n);
    printf("%d\n",solve(n));
}
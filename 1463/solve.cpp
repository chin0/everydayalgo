#include <iostream>
#include <algorithm>
#include <vector>


using namespace std;

int dp[1000001];

int solve(int n) {
    dp[0] = 0;
    dp[1] = 0;
    dp[2] = 1;
    dp[3] = 1;
    for(int i = 4; i <= n; i++) {
        dp[i] = dp[i-1];
        if(i % 3 == 0)
            dp[i] = min(dp[i],dp[i/3]);
        if(i % 2 == 0)
            dp[i] = min(dp[i],dp[i/2]);
        dp[i] += 1;
    }

    return dp[n];
}
int main(void) {
    int n;
    cin >> n;

    ios_base::sync_with_stdio(false);
    cout << solve(n) << endl;
}

#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

int dp[1001][1001];

int main(void)
{
    cin.tie(NULL);
    ios::sync_with_stdio(false);

    string s1, s2;
    cin >> s1;
    cin >> s2;
    int n = s1.length();
    int m = s2.length();

    for(int i = 1; i <= m; i++) {
        for(int j = 1; j <= n; j++) {
            if(s1[j-1] == s2[i-1]) dp[i][j] = dp[i-1][j-1] + 1;
            else {
                dp[i][j] = max(dp[i][j-1],dp[i-1][j]);
            }
        }
    }
    cout << dp[m][n] << endl;
}

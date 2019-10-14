#include <iostream>
#include <string>

using namespace std;

//0의 예외처리에 주의
//s[i]가 0이 아니면 그 전까지 나온 수에다가 그 숫자 카드 한장 추가하면 되므로 dp[i-1]
//s[i]와 s[i-1]을 합친수가 10이상, 34 이하라면 이어붙인 카드에다가 그전 카드 i-2개의 경우의 수를 더해주면 되므로 dp[i-2]를 더해주면 됨.

int dp[41];
int main(void)
{
    int combined;
    string s;
    cin >> s;
    s = '0' + s;
    combined = (s[1] - '0') * 10 + (s[2] - '0');
    dp[0] = 1;
    s[1] -= '0';
    if(s[1]) {
        dp[1]= 1;
    }

    for(size_t i = 2; i < s.length(); i++) {
        s[i] -= '0';
        if(s[i]) dp[i] = dp[i-1];
        combined = s[i-1] * 10 + s[i];
        if(combined >= 10 && 34 >= combined) dp[i] += dp[i-2];
    }
    cout << dp[s.length() - 1] << endl;
}

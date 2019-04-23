#include <array>
#include <iostream>
#include <algorithm>

using namespace std;

array<int, 1001> prices;
array<int, 1001> dp;

//n^2에 풀수있음.
// dp[i]를 i개를 구매하는데 드는 최대 비용이라고 하자.
// 그러면 dp[i]는 총 i개의 경우가 나옴.
// 1개짜리 카드팩을 사면 n-1개의 카드를 최대값이 나오게 구매해야하므로 prices[1] + dp[i-1].
//이런식으로 i가지의 경우가 나오고 이중에 최댓값이 곧 dp[i]가 되겠다.
// 이렇게 가능한 경우의 수를 생각하고 점화식을 세우면 편하다.
int main(void) 
{
    ios::sync_with_stdio(false);
    int n,current;
    cin >> n;
    for(int i = 1; i <= n; i++) {
        cin >> prices[i];
    }

    dp[0]=prices[0]=0;
    for(int i = 1; i <= n; i++) {
        for(int j = 1; j <= i; j++) {
            dp[i] = max(dp[i], dp[i-j]+prices[j]);
        }
    }
    cout << dp[n] << endl;
}
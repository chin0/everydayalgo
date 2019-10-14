#include <cstdio>
#include <algorithm>

using namespace std;

//전체탐색은 모든 조합을 다 해보면 2^n만큼 걸릴거임.
int dp[101][100001]; //dp[i][j] -> i번째 물건까지 포함했을때 가방 무게가 j일때 최대가치

int w[101];
int v[101];
int main(void)
{
    int n,k;

    scanf("%d %d", &n, &k);

    for(int i = 1; i <= n; i++) {
        scanf("%d %d", &w[i], &v[i]);
    }


    for(int i = 1; i <= n; i++) {
        //정방향으로 돌리면 중복, 
        for(int j = 1; j <= k; j++) {
            //현재 보석을 넣거나, 안넣거나.
            //넣는경우, 그 보석의 무게를 뺀만큼 물건을 더 넣을수있음.
            // 아닌 경우는 그보석을 빼고 남은만큼 물건을 넣을수있음.
            // 중요한것 : 보석을 포함할까 안할까?와 배낭의 크기로 부분문제 정의.
            if(j - w[i] < 0) {
                dp[i][j] = dp[i-1][j];
            } else {
                dp[i][j] = max(dp[i-1][j - w[i]] + v[i], dp[i-1][j]);
            }
        }
    }
    printf("%d\n",dp[n][k]);
}

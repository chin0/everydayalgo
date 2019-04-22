#include <stdio.h>
#include <algorithm>
using namespace std;

int data[1001];
int dp1[1001];
int dp2[1001];
//거꾸로 LIS돌린거 dp2, 정방향으로 LIS dp1. n번째를 기준으로 하는 바이토닉 수열은 dp2[n] + dp1[n] - 1; (공통 부분 하나 빼줌.)
//dp1[i]는 정방향으로 i까지의 최장 증가 수열, dp2는 뒤에서부터 i까지의 최장 증가 수열. 그러므로 data[i]라는 원소가 중복됨.
// 따라서 1을 빼줌.
void solve1(int n)
{
    for(int i = 0; i < n; i++) {
        dp1[i] = 1;
        for(int j= 0; j < i; j++) {
            if(data[i] > data[j]) {
                dp1[i] = max(dp1[i], dp1[j] + 1);
            }
        }
    }
}
//reverse lis
void solve2(int n)
{
    for(int i = n-1; i >=0; i--) {
        dp2[i] = 1;
        for(int j = i; j < n; j++) {
            if(data[i] > data[j]) {
                dp2[i] = max(dp2[i],dp2[j] + 1);
            }
        }
    }
}

int main(void)
{
    int n;
    scanf("%d",&n);
    for(int i = 0; i < n; i++ ) {
        scanf("%d",&data[i]);
    }
    solve1(n);
    solve2(n);
    int ans = 0;
    for(int i = 0; i < n; i++) {
        ans = max(ans, dp1[i] + dp2[i] - 1);
    }
    printf("%d\n",ans);
}

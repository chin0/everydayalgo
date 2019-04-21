#include <stdio.h>
#include <algorithm>
using namespace std;

int data[1001];
int dp[1001];

//dp[n]을 data[n]을 마지막 수로 가지는 최장 길이 수열의 길이라고 두자.
//그러면 dp[i]은 data[i]보다 작은 수들의 집합이 될것이다.
// dp[i]는 i보다 작은 j에 대하여 data[i] > data[j]이면 dp[j]+1이 최댓값이 될수도 있고 기존 dp[i]가 최댓값이 될수도있음.
// n log n 알고리즘도 있다는데 공부해봐야할듯.
int solve(int n)
{
    int ans = 0;
    for(int i = 0; i < n; i++) {
        dp[i] = 1;
        for(int j= 0; j < i; j++) {
            if(data[i] > data[j]) {
                dp[i] = max(dp[i], dp[j] + 1);
            }
        }
        ans = max(ans,dp[i]);
    }
    return ans;
}

int main(void)
{
    int n;
    scanf("%d",&n);
    for(int i = 0; i < n; i++ ) {
        scanf("%d",&data[i]);
    }
    printf("%d\n",solve(n));
}

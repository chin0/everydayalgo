#include <stdio.h>
#include <algorithm>
using namespace std;

int data[1001];
int dp[1001];

//11053번 변형.
int solve(int n)
{
    int ans = 0;
    for(int i = 0; i < n; i++) {
        dp[i] = data[i];
        for(int j= 0; j < i; j++) {
            if(data[i] > data[j]) {
                dp[i] = max(dp[i], dp[j] + data[i]);
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

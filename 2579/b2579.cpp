#include <stdio.h>
#include <algorithm>
#include <vector>

using namespace std;

int main(void) 
{
    int n,temp;
    vector<int> score;
    scanf("%d",&n);
        
    //dp[n][0] = 한칸 dp[n][1] = 두칸
    int dp[n];

    for(int i = 0; i < n; i++) {
        scanf("%d",&temp);
        score.push_back(temp);
    }

    dp[0] = score[0];
    dp[1] = max(score[1],score[0]+score[1]);
    dp[2] = max(score[0] + score[2], score[1] + score[2]);
    for(int i = 3; i < n; i++) {
        dp[i] = max(score[i-1] + dp[i-3] + score[i], dp[i-2] + score[i]);
    }
    printf("%d\n",dp[n-1]);
}


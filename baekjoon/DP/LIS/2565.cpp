#include <cstdio>
#include <vector>
#include <utility>
#include <algorithm>

using namespace std;

int dp[100];
int main(void)
{
    int n;

    vector<pair<int,int>> vec;
    scanf("%d", &n);

    for(int i = 0; i < n; i++) {
        int a,b;
        scanf("%d %d", &a, &b);
        vec.push_back({a,b});
    }

    sort(vec.begin(), vec.end());
    int longest=0;
    for(int i = 0; i < n; i++) {
        dp[i] = 1;
        for(int j = 0; j < i; j++) {
            if(vec[i].second > vec[j].second) {
                if(dp[i] < dp[j] +1) {
                    dp[i] = dp[j] + 1;
                }
            }
        }
        if(longest < dp[i] || longest == 0) longest = dp[i];
    }
    printf("%d\n",n - longest);
    return 0;
}


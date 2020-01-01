#include <cstdio>
#include <vector>
#include <algorithm>

using namespace std;

long long dp[10001];

int main(void)
{
    int n,m;

    vector<int> memory;
    vector<int> c;

    scanf("%d %d", &n, &m);

    for(int i = 0; i < n; i++) {
        int temp;
        scanf("%d", &temp);
        memory.push_back(temp);
    }

    int sum = 0;
    for(int i = 0; i < n; i++) {
        int temp;
        scanf("%d", &temp);
        c.push_back(temp);
        sum += temp;
    }

    for(int i = 0; i < n; i++) {
        for(int j = sum; j >= c[i]; j--) {
            dp[j]= max(dp[j-c[i]] + memory[i] , dp[j]);
        }
    }

    for(int i = 0; i <= sum; i++) {
        if(dp[i] >= m){
            printf("%d\n",i);
            break;
        }
    }
}

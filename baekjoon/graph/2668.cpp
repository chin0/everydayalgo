#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;

//텀프로젝트와 유사한 문제.
int n;
int permutation[101];
int which_search[101];
int d[101]; //몇번째로?


vector<int> dfs(int start, int c, int step) {
    if(d[start] != 0) {
        vector<int> ret;
        if(step != which_search[start]) {
            return ret;
        } else {
            ret.push_back(start);
            for(int i = permutation[start]; i != start; i = permutation[i]) {
                ret.push_back(i);
            }
            return ret;
        }
    }
    d[start] = c;
    which_search[start] = step;
    return dfs(permutation[start], c+1, step);
}
int main(void)
{
    scanf("%d", &n);

    for(int i = 1; i <= n; i++) {
        scanf("%d", &permutation[i]);
    }
    vector<int> ans;
    for(int i = 1; i <= n; i++) {
        if(d[i] == 0) {
            vector<int> cycle = dfs(i,1,i);
            for(auto i : cycle) ans.push_back(i);
        }
    }

    sort(ans.begin(), ans.end());
    printf("%d\n", ans.size());
    for(auto i : ans) {
        printf("%d ", i);
    }
    printf("\n");
}

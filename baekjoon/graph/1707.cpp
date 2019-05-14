//두 인접한 그래프를 두 집합으로 나눴을때 각 집합에 속한 정점끼리는 인접하지 않은 그래프.
// 처음 시작 지점을 집합 1에 넣느다고 할때 인접한 정점은 집합 1에 들어가면 안댐.
// 이런식으로 bfs또는 dfs로 탐색해주면 댈듯.
// 이거 union-find로도 가능해보임. 생각좀 해보자.

#include <stdio.h>
#include <queue>
#include <vector>
#include <algorithm>

using namespace std;

int color[20001]; //0: 방문 ㄴ, 1: 집합 1, 2: 집합 2

bool bfs(int v, vector<int> connected[],int n) {
    queue<int> s;
    s.push(v);
    color[v] = 1;
    while(!s.empty()) {
        int current = s.front();
        s.pop();
        for(auto i : connected[current]) {
            if(color[i]) {
                if(color[i] + color[current] != 0) return false;
            } else {
                s.push(i);
                color[i] = color[current] * -1;
             }
        }
    }
    return true;
}

int main(void)
{
    int t;
    scanf("%d",&t);
    for(int i = 0; i < t; i++) {
        int n,m;
        scanf("%d %d", &n, &m);
        vector<int> connected[n+1];
        fill(color, color + (n+1), 0);

        for(int j = 0; j < m; j++) {
            int a,b;
            scanf("%d %d", &a, &b);
            connected[a].push_back(b);
            connected[b].push_back(a);
        }
        bool is_failed = false;
        for(int j = 1; j <= n; j++) {
            if(color[j]) continue;
            if(!bfs(j,connected,n)) {
                is_failed = true;
                break;
            }
        }
        if(is_failed) printf("NO\n");
        else printf("YES\n");
    }
}
//트리 지름구하는 코드.
#include <queue>
#include <cstdio>
#include <vector>
#include <cstring>

using namespace std;

struct Edge {
    int to;
    int cost;
    Edge(int to, int cost) : to(to), cost(cost) {
    }
};

vector<Edge> a[100001];
bool check[100001];
int dist[100001];

void bfs(int start)
{
    memset(dist,0, sizeof(dist));
    memset(check,false, sizeof(check));
    queue<int> q;

    check[start] = true;
    q.push(start);
    while(!q.empty()) {
        int x = q.front();
        q.pop();
        for(int i = 0; i < a[x].size(); i++) {
            Edge &e = a[x][i];
            if(check[e.to] == false) {
                dist[e.to] = dist[x] + e.cost;
                q.push(e.to);
                check[e.to] = true;
            }
        }
    }
}

int main()
{
    int n;
    scanf("%d", &n);
    for(int i = 1; i <=n; i++) {
        int x;
        scanf("%d", &x);
        while(true) {
            int y, z;
            scanf("%d", &y);
            if(y == -1) break;
            scanf("%d", &z);
            a[x].push_back(Edge(y,z));
        }
    }
    bfs(1);
    //루트에서 시작해서 가장 먼 노드 찾기.
    int start = 1;
    for(int i = 2; i <=n; i++) {
        if(dist[i] > dist[start]) {
            start = i;
        }
    }
    //그 노드에서 다시 제일 먼거 찾으면 그게 답임.
    bfs(start);
    int ans = dist[1];
    for(int i = 2; i <=n; i++) {
        if(ans < dist[i]) {
            ans = dist[i];
        }
    }
    printf("%d\n",ans);
    return 0;
}

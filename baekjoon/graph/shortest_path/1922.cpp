#include <vector>
#include <queue>
#include <vector>
#include <utility>
using namespace std;

struct Edge {
    int start;
    int end;
    int cost;
    Edge() : start(0), end(0), cost(0) {
    }
    Edge(int start, int end, int cost) : start(start), end(end), cost(cost) {
    }
    bool operator < (const Edge &other) const {
        return cost > other.cost;
    }
};

vector<pair<int,int>> a[1001];
bool c[1001];

int main()
{
    int n,m;
    scanf("%d", &n);
    scanf("%d", &m);
    for(int i = 0; i < m; i++) {
        int start,end,cost;
        scanf("%d %d %d", &start, &end, &cost);
        a[start].push_back(make_pair(end,cost));
        a[end].push_back(make_pair(start,cost));
        //양방향 그래프라서 위와 같이 해줘야댐.
    }

    c[1] = true;
    priority_queue<Edge> q;

    for(int i = 0; i < a[i].size(); i++) {
        q.push(Edge(1,a[1][i].first, a[1][i].second));
    }
    int ans = 0;
    for(int i = 0; i < n-1; i++) {
        Edge e;
        while(!q.empty()) {
            e = q.top();
            q.pop();
            if(c[e.end] == false)
                break;
        }
        c[e.end] = true;
        ans += e.cost;
        int x = e.end;
        for(int i = 0; i < a[x].size(); i++) {
            q.push(Edge(x,a[x][i].first,a[x][i].second));
        }
    }
    printf("%d\n",ans);
    return 0;
}

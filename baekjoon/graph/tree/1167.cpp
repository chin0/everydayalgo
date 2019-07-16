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

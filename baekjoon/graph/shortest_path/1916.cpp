#include <cstdio>
#include <vector>

using namespace std;

struct Edge {
    int to;
    int cost;
    Edge(int to, int cost) : to(to), cost(cost) {}
};

vector<Edge> a[1001];
int dist[1001];
bool check[1001];
int inf = 1000000000;
int main()
{
    int n,m;
    scanf("%d %d", &n, &m);

    for(int i = 0; i < m; i++) {
        int x,y,z;
        scanf("%d %d %d", &x, &y, &z);
        a[x].push_back(Edge(y,z));
    }
    int start,end;
    scanf("%d %d", &start, &end);
    for(int i = 1; i <= n; i++) {
        dist[i] = inf;
    }
    dist[start] = 0;
    for(int k = 0; k < n-1; k++) {
        int m = inf + 1;
        int x= -1;
        //가장 작은 d[i]값 찾기
        for(int i = 1; i<= n; i++) {
            if(check[i] == false && m > dist[i]) {
                m = dist[i];
                x = i;
            }
        }
        check[x]= true;
        //그 정점에서 방문할수있는 간선들 모두 식 체크.
        for(int i = 0; i < a[x].size(); i++) {
            int y = a[x][i].to;
            if(dist[y] > dist[x] + a[x][i].cost) {
                dist[y] = dist[x] + a[x][i].cost;
            }
        }
    }
    printf("%d\n",dist[end]);
    return 0;
}

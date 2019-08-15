//이건 1->V1, V1->V2, V2->N 이렇게 세번 다익스트라 돌리면 댐.
#include <vector>
#include <algorithm>
#include <cstdio>

using namespace std;

int a[1001][1001];
int dist[1001];
bool check[1001];
int inf = 100000000;
int n;

vector<int> dijkstra(int start)
{
    for(int i = 1; i <= n; i++) {
        dist[i] = inf;
        check[i] = false;
    }

    dist[start] = 0;
    for(int k = 0; k < n-1; k++) {
        int m = inf+1;
        int x= - 1;
        for(int i = 1; i <= n; i++) {
            if(check[i] == false && m > dist[i]) {
                m = dist[i];
                x= i;
            }
        }
        check[x] = true;
        for(int i = 1; i <= n; i++) {
            if(dist[i] > dist[x] + a[x][i]) {
                dist[i] = dist[x] + a[x][i];
            }
        }
    }
    return vector<int>(dist,dist+n+1);
}

int main() {
    scanf("%d", &n);

    for(int i = 1; i <= n; i++) {
        for(int j = 1; j <= n; j++) {
            a[i][j] = inf;
        }
    }
    int m;
    scanf("%d", &m);
    for(int i = 0; i < m; i++) {
        int x,y,z;
        scanf("%d %d %d", &x, &y, &z);
        a[x][y] =z;
        a[y][x]= z;
    }
    int v1,v2;
    scanf("%d %d", &v1, &v2);
    vector<int> dstart = dijkstra(1);
    vector<int> d1 = dijkstra(v1);
    vector<int> d2 = dijkstra(v2);
    int ans = dstart[v1] + d1[v2] + d2[n];
    int ans2 = dstart[v2] + d2[v1] + d1[n];
    if(ans > ans2) {
        ans = ans2;
    }
    if(ans >= inf) //그러한 경로가 없을
        ans = -1;
    printf("%d\n",ans);
    return 0;
}

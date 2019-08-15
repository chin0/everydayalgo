#include <cstdio>
#include <vector>

using namespace std;

struct Edge {
    int from;
    int to;
    int cost;
};

int d[501];
int inf = 100000000;
int main() {
    int t;
    scanf("%d", &t);
    while(t--) {
        int n,m,w;
        scanf("%d %d %d", &n, &m, &w);
        vector<Edge> a(2*m+w); //도로는 양방향이므로 2*m

        for(int i = 0; i < m; i++) {
            scanf("%d %d %d", &a[i].from, &a[i].to, &a[i].cost);
            a[i+m] = a[i];
            swap(a[i+m].from,a[i+m].to);
        }

        for(int i = 2*m; i < 2*m + w; i++) {
            scanf("%d %d %d", &a[i].from, &a[i].to, &a[i].cost);
            a[i].cost *= -1;
        }
        for(int i = 1; i <= n; i++) {
            d[i] = inf;
        }
        d[1] = 0;
        m= 2*m + w;
        bool ok = false;
        for(int i = 1; i <= n; i++) {
            for(int j = 0; j < m; j++) {
                int x = a[j].from;
                int y = a[j].to;
                int z = a[j].cost;
                if(d[x] != inf && d[y] > d[x]+z) {
                    d[y] = d[x]+z;
                    if(i == n) ok = true;
                }
            }
        }
        if(ok) {
            printf("YES\n");
        }else {
            printf("NO\n");
        }
    }
}

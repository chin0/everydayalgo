#include <queue>
#include <vector>
#include <cstdio>

using namespace std;

const int MAX = 100111;
vector<int> a[MAX];
queue<int> q;
int depth[MAX],parent[MAX];
bool check[MAX];
int main(void)
{
    int n;
    scanf("%d",&n);
    for (int i=0; i<n-1; i++) {
        int u,v;
        scanf("%d %d",&u,&v);
        a[u].push_back(v);
        a[v].push_back(u);
    }

    depth[1] = 0;
    check[1] = true;
    q.push(1);
    parent[1] = 0;

    while (!q.empty()) {
        int x = q.front();
        q.pop();
        for (int y : a[x]) {
            if (!check[y]) {
                depth[y] = depth[x] + 1;
                check[y] = true;
                parent[y] = x;
                q.push(y);
            }
        }
    }
    for(int i = 2; i <= n; i++) {
        printf("%d\n", parent[i]);
    }
}

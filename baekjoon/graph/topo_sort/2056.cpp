#include <cstdio>
#include <vector>
#include <queue>

using namespace std;

vector<int> a[10001];
int ind[10001];
int work[10001];
int d[10001];

int main()
{
    int n;
    scanf("%d", &n);
    for(int i = 1; i <= n; i++) {
        scanf("%d", &work[i]);
        int cnt;
        scanf("%d", &cnt);
        for(int j = 0; j <cnt; j++) {
            int x;
            scanf("%d", &x);
            a[x].push_back(i);
            ind[i] += 1;
        }
    }
    queue<int> q;
    for(int i=1; i<=n;i++) {
        if(ind[i] == 0) {
            q.push(i);
            d[i] = work[i];
        }
    }

    for(int k = 0; k < n; k++) {
        int x = q.front();
        q.pop();
        for(int i = 0; i < a[x].size(); i++) {
            int y = a[x][i];
            ind[y] -= 1;
            if(d[y] < d[x]+work[y]) {
                d[y] = d[x]+work[y];
            }
            if(ind[y] == 0)
                q.push(y);
        }
    }
    int ans = 0;
    for(int i = 1; i <= n; i++) {
        if(ans < d[i])
            ans = d[i];
    }
    printf("%d\n",ans);
    return 0;
}

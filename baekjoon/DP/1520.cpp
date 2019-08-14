#include <cstdio>
#include <cstring>

int n,m;
int a[500][500];
long long d[500][500];

int dx[] = {0,0,1,-1};
int dy[] = {1,-1,0,0};

long long go(int x, int y) {
    if(x == n-1 && y == m-1)
        return 1;
    if(d[x][y] != -1)
        return d[x][y];

    long long &ans = d[x][y];
    ans = 0;
    for(int k = 0; k < 4; k++) {
        int nx = x + dx[k];
        int ny = y + dy[k];
        if(0 <= nx && nx < n && 0 <= ny && ny < m) {
            if(a[x][y] > a[nx][ny])
                ans += go(nx,ny);
        }
    }
    return ans;
}

int main()
{
    scanf("%d %d", &n ,&m);
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++)
            scanf("%d", &a[i][j]);
    }
    memset(d,-1,sizeof(d));
    printf("%lld\n",go(0,0));
    return 0;
}

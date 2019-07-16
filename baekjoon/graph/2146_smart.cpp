#include <cstdio>
#include <queue>
//백준강의 : https://gist.github.com/Baekjoon/8eaddae5eb16592a1c51
// 모든 색깔에 대하여 땅을 확장해주면서(bfs) 인접한곳의 색깔이 다르면 다리를 만들수 있음.
// bfs를 한번만 하면 되므로 더 빠름. 
using namespace std;
int a[100][100];
int g[100][100];
int d[100][100];
int dx[] = {0,0,1,-1};
int dy[] = {1,-1,0,0};
int main() {
    int n;
    scanf("%d",&n);
    for (int i=0; i<n; i++) {
        for (int j=0; j<n; j++) {
            scanf("%d",&a[i][j]);
        }
    }
    int cnt = 0;
    for (int i=0; i<n; i++) {
        for (int j=0; j<n; j++) {
            if (a[i][j] == 1 && g[i][j] == 0) {
                g[i][j] = ++cnt;
                queue<pair<int,int>> q;
                q.push(make_pair(i,j));
                while (!q.empty()) {
                    int x = q.front().first;
                    int y = q.front().second;
                    q.pop();
                    for (int k=0; k<4; k++) {
                        int nx = x+dx[k];
                        int ny = y+dy[k];
                        if (0 <= nx && nx < n && 0 <= ny && ny < n) {
                            if (a[nx][ny] == 1 && g[nx][ny] == 0) {
                                g[nx][ny] = cnt;
                                q.push(make_pair(nx,ny));
                            }
                        }
                    }
                }
            }
        }
    }
    queue<pair<int,int>> q;
    for (int i=0; i<n; i++) {
        for (int j=0; j<n; j++) {
            d[i][j] = -1;
            if (a[i][j] == 1) {
                q.push(make_pair(i,j));
                d[i][j] = 0;
            }
        }
    }
    while (!q.empty()) {
        int x = q.front().first;
        int y = q.front().second;
        q.pop();
        for (int k=0; k<4; k++) {
            int nx = x+dx[k];
            int ny = y+dy[k];
            if (0 <= nx && nx < n && 0 <= ny && ny < n) {
                if (d[nx][ny] == -1) {
                    d[nx][ny] = d[x][y] + 1;
                    g[nx][ny] = g[x][y];
                    q.push(make_pair(nx,ny));
                }
            }
        }
    }
    int ans = -1;
    for (int i=0; i<n; i++) {
        for (int j=0; j<n; j++) {
            for (int k=0; k<4; k++) {
                int x = i+dx[k];
                int y = j+dy[k];
                if (0 <= x && x < n && 0 <= y && y < n) {
                    if (g[i][j] != g[x][y]) {
                        if (ans == -1 || ans > d[i][j] + d[x][y]) {
                            ans = d[i][j] + d[x][y];
                        }
                    }
                }
            }
        }
    }
    printf("%d\n",ans);
    return 0;
}

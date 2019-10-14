#include <cstdio>
#include <cstring>
#include <queue>
#include <utility>

using namespace std;

char map[50][50];
int d[50][50];
bool visited[50][50];
int ans = 0;

int dx[] = {0,0,1,-1};
int dy[] = {1,-1,0,0};
int bfs(int x,int y,int h,int w) {
    memset(visited,0,sizeof(bool) * 50*50);
    memset(d,0,sizeof(int) * 50*50);
    int m = 0;
    queue<pair<int,int>> q;
    q.push({x,y});
    visited[y][x] = true;
    d[y][x] = 1;


    while(!q.empty()) {
        auto cur = q.front();
        q.pop();
        int x = cur.first;
        int y = cur.second;

        for(int i = 0; i < 4; i++) {
            int cur_x = x + dx[i];
            int cur_y = y + dy[i];
            if(cur_x < w && cur_x >= 0 && cur_y < h && cur_y >= 0) {
                if(map[cur_y][cur_x] == 'L' && !visited[cur_y][cur_x]) {
                    d[cur_y][cur_x] = d[y][x] + 1;
                    m = max(m, d[cur_y][cur_x]);
                    visited[cur_y][cur_x] = true;
                    q.push({cur_x,cur_y});
                }
            }
        }
    }
    return m;
}
int main(void)
{
    int h,w;

    scanf("%d %d", &h, &w);

    for(int i = 0; i < h; i++) {
        scanf("%s", map[i]);
    }

    for(int i = 0; i < h; i++) {
        for(int j = 0; j < w; j++) {
            if(map[i][j] == 'L') {
                ans = max(ans, bfs(j,i,h,w));
            }
        }
    }
    printf("%d\n",ans-1);
}

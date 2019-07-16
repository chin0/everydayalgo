#include <cstdio>
#include <queue>
#include <cstring>
#include <algorithm>

using namespace std;

int h, w;
int map[100][100];
int visit[100][100];

void bfs(int x, int y,int cnt) {
    queue<pair<int,int> > q;
    int dx[8] = {-1,1,0,0,-1,-1,1,1};
    int dy[8] = {0,0,-1,1,-1,1,-1,1};

    q.push(make_pair(x,y));
    visit[y][x] = cnt;
    while(!q.empty()) {
        pair<int,int> current = q.front();
        q.pop();
        int x = current.first;
        int y = current.second;

        for(int i = 0; i < 8; i++) {
            int nx = x+ dx[i];
            int ny = y + dy[i];
            if(nx >= 0 && nx < w && ny >= 0 && ny < h) {
                if(map[ny][nx] == 1 &&visit[ny][nx]==0) {
                    q.push(make_pair(nx,ny));
                    visit[ny][nx] = cnt;
                }
            }
        }
    }
}


int main(void)
{
    while(1) {
    int ans = 0;
    scanf("%d %d", &w, &h);
    if(w == 0 && h == 0) {
        return 0;
    }
    for(int i = 0; i < h; i++) {
        for(int j = 0; j < w; j++) {
            scanf("%d", &map[i][j]);
            visit[i][j] = false;
        }
    }

    int cnt = 0;
    for(int i = 0; i < h; i++) {
        for(int j = 0; j < w; j++) {
            if(map[i][j] == 1  && visit[i][j] == 0) {
                ans++;
                bfs(j,i,++cnt);
            }
        }
    }
    printf("%d\n",cnt);
    }
}

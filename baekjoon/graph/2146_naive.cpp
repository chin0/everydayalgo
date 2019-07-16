#include <cstdio>
#include <cstring>
#include <queue>
#include <utility>
#include <cmath>

//이건 걍 각 그룹에 대하여 다 최단거리를 돌려줘야해서 존나 느림.
using namespace std;

int n;
int map[101][101];
int d[101][101];
int group[101][101];

int dx[4] = {0,0,1,-1};

int dy[4] = {1,-1,0,0};

void grouping(int x, int y, int groupnum)
{
    group[x][y] = groupnum;
    for(int i = 0; i < 4; i++) {
        int nx = dx[i] + x;
        int ny = dy[i] + y;
        if(nx >= 0 && nx < n && ny >= 0 && ny < n) {
            if(group[nx][ny] == 0 && map[nx][ny] == 1)
                grouping(nx,ny,groupnum);
        } 
    }
}

int getdistance(int groupnum)
{
    queue<pair<int,int> > q;

    memset(d,0,sizeof(d));

    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            d[i][j] = -1;
            if(group[i][j] == groupnum){
                d[i][j] = 0;
                q.push(make_pair(i,j));
            }
        }
    }

    //땅을 확장시키고
    while(!q.empty()) {
        pair<int,int> current = q.front();
        int x = current.first;
        int y = current.second;
        q.pop();

        for(int i = 0; i < 4; i++) {
            int nx = x + dx[i];
            int ny = y + dy[i];
            if(nx >= 0 && nx < n && ny >= 0 && ny < n) {
                if(d[nx][ny] == -1) {
                    d[nx][ny] = d[x][y] + 1;
                    q.push(make_pair(nx,ny));
                }
            }
        }
    }

    //그걸로 최단거리를 구한다.
    int result = -1;
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            if(group[i][j] != groupnum && map[i][j] == 1) {
                if(result == -1 || result > d[i][j] - 1) {
                    result = d[i][j] -1;
                }
            }
        }
    }
    return result;
}
int main(void)
{
    scanf("%d", &n);
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            scanf("%d", &map[i][j]);
        }
    }

    int cnt = 1;
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            if(group[i][j] == 0 && map[i][j] == 1) {
                grouping(i,j,cnt);
                cnt++;
            }
        }
    }

    int result = -1;
    for(int i = 1; i < cnt; i++) {
        if(result != -1) {
            result = min(result, getdistance(i));
        } else {
            result = getdistance(i);
        }
    }
    printf("%d\n",result);
}

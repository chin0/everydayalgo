#include <cstdio>
#include <cstring>

//아니 왼쪽 위부터 채운다고 가정했으면 경우의 수좀 제대로 세자.
// 블럭 경우의 수를 잘못둬서 오답나네..
//전체적인 아이디어는 피크닉과 동일한게 구현이 좀 귀찮음.
char map[20][20];
int dx[4][2] = {{1,0},{1,1},{0,1},{-1,0}};
int dy[4][2] = {{0,1},{1,0},{1,1},{1,1}};

int h, w;
inline bool check(int x, int y) {
    if(x >= 0 && x < w
       && y >= 0 && y < h && map[y][x] == '.') return true;
    return false;
}

int solve() {
    int firstx = -1, firsty = -1;
    bool finished = true;
    for(int i = 0; i < h; i++) {
        for(int j = 0; j < w; j++) {
            if(map[i][j] == '.') {
                finished = false;
                firstx = j;
                firsty = i;
                break;
            }
        }
        if(!finished) break;
    }
    if(finished) return 1;

    int cnt = 0;
    for(int i = 0; i < 4; i++) {
        int x1 = firstx + dx[i][0],
            x2 = firstx + dx[i][1],
            y1 = firsty + dy[i][0],
            y2 = firsty + dy[i][1];
        if(check(x1,y1) && check(x2,y2)) {
            map[firsty][firstx] = '#';
            map[y1][x1] = map[y2][x2] = '#';
            cnt += solve();
            map[firsty][firstx] = '.';
            map[y1][x1] = map[y2][x2] = '.';
        }
    }
    return cnt;
}
int main(void)
{
    int c;
    scanf("%d", &c);
    for(int p = 0; p < c; p++) {
        scanf("%d %d", &h, &w);
        memset(map,0, sizeof(char) * h * w);

        for(int i = 0; i < h; i++) {
            scanf("%s", map[i]);
        }
        printf("%d\n", solve());
    }
}

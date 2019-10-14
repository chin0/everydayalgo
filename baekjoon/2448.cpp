#include <cstdio>

char map[10000][10000];

//삼각형의 높이, 맨 위 꼭짓점의 x, y좌표
void solve(int height, int x, int y) {
    if(height == 3) {
        map[y][x] = '*';
        map[y+1][x-1] = '*';
        map[y+1][x] = ' ';
        map[y+1][x+1] = '*';
        map[y+2][x-2] = '*';
        map[y+2][x-1] = '*';
        map[y+2][x] = '*';
        map[y+2][x+1] = '*';
        map[y+2][x+2] = '*';
        return;
    }
    solve(height/2, x,y);
    solve(height/2, x-height/2, y+height/2);
    solve(height/2, x+height/2, y+height/2);
}
int main(void)
{
    int n;
    scanf("%d", &n);
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < 2*n-1; j++) {
            map[i][j] = ' ';
        }
    }
    solve(n,n-1,0);

    for(int i = 0; i < n; i++) {
        for(int j = 0; j < 2*n-1; j++) {
            printf("%c",map[i][j]);
        }
        printf("\n");
    }
}

#include <stdio.h>

int a[128][128];

int blue,white;

bool is_same(int x, int y, int n)
{
    for(int i = x; i < x+n; i++) {
        for(int j = y; j < y+n; j++) {
            if(a[x][y] != a[i][j]) {
                return false;
            }
        }
    }
    return true;
}

void solve(int x, int y, int n)
{
    if(is_same(x,y,n)) {
        if(a[x][y]) blue++;
        else white++;
        return;
    }

    int m = n/2;

    for(int i = 0; i < 2; i++) {
        for(int j = 0; j < 2; j++) {
            solve(x+m*i, y+m*j, m);
        }
    }
}

int main(void)
{
    int n;
    scanf("%d", &n);

    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            scanf("%d", &a[i][j]);
        }
    }

    solve(0,0,n);
    printf("%d\n%d\n", white,blue);
}

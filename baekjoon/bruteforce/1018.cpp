#include <cstdio>
#include <algorithm>

using namespace std;

char board[50][50];

int count(char scolor, int x, int y) {
    int ans = 0;
    //배열 대각선 순회.
    for(int i = 0; i <= 15; i++) {
        for(int j = 0; j <= 7; j++) {
            int cx = x + i - j;
            if(cx >= x && cx <= x + 7){
                int cy =y + j;
                if(board[cy][cx] != scolor) 
                    ans += 1;
            }
        }
        scolor = (scolor == 'B') ? 'W' : 'B';
    }
    return ans;
}
int main(void)
{
    int n,m;
    scanf("%d %d", &n, &m);

    for(int i = 0; i < n; i++) {
        scanf("%s", board[i]);
    }

    int ans = 2147483647;

    for(int i = 0; i <= n-8; i++) {
        for(int j = 0; j <= m-8; j++) {
            ans = min(ans, count('B',j,i));
            ans = min(ans, count('W',j,i));
        }
    }
    printf("%d\n",ans);
}

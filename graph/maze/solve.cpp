#include <cstdio>
#include <queue>
#include <utility>

using namespace std;

using loc = std::pair<int, int>;
int dx[4] = {1,-1,0,0};
int dy[4] = {0,0,1,-1};


int map[100][100];
int check[100][100];

int main(void) {
    int m,n;
    int result = 0;
    queue<loc> q;
    q.push(loc(0,0));
    scanf("%d %d",&n,&m);


    
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            scanf("%1d",&map[i][j]);
        }
    }

    
    int value;
    while(!q.empty()) {
        loc current = q.front();
        q.pop();
        int x = current.first, y = current.second;
        if(x == m-1 && y == n-1) break;
        for(int i = 0; i < 4; i++) {
            int next_x = x + dx[i];
            int next_y = y + dy[i];

            //if(next_x > 0 && next_x < m && next_y < n && next_y > 0 && map[next_y][next_x] == 1 && check[next_y][next_x] == 0) {
            if(next_x >= 0 && next_y >= 0 && next_x < m && next_y < n && map[next_y][next_x] == 1 && check[next_y][next_x] == 0) {
                check[next_y][next_x] = check[y][x]+1;
                q.push(loc(next_x,next_y));
            }
        }
    }
    printf("%d\n",check[n-1][m-1] + 1);
    return 0;
}

    

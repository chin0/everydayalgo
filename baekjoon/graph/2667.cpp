#include <queue>
#include <cstdio>
#include <vector>
#include <utility>
#include <algorithm>

using namespace std;

int n;
int map[25][25];
bool is_visited[25][25];
using coordinate = pair<int,int>;

int dx[4] = {0,0,1,-1};
int dy[4] = {1,-1,0,0};

inline bool is_coordinate(int x, int y) {
    return (x < n && x >= 0
             && y < n && y >= 0);
}
int solve(coordinate start)
{
    int count= 1;
    queue<coordinate> q;

    q.push(start);
    is_visited[start.second][start.first] = true;
    while(!q.empty()) {
        coordinate current = q.front();
        q.pop();
        int x = current.first, y = current.second;
        for(int i = 0; i < 4; i++) {
            int cur_x = x + dx[i];
            int cur_y = y + dy[i];
            if(is_coordinate(cur_x,cur_y) && !is_visited[cur_y][cur_x] && map[cur_y][cur_x] == 1) {
                q.push(make_pair(cur_x,cur_y));
                is_visited[cur_y][cur_x] = true;
                count++;
            }
        }
    }
    return count;
}
int main(void)
{
    int apart = 0;
    vector<int> count;
    scanf("%d", &n);
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            scanf("%1d", &map[i][j]);
        }
    }

    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            if(map[i][j] && !is_visited[i][j]) {
                apart++;
                count.emplace_back(solve(make_pair(j,i)));
            }
        }
    }
    sort(count.begin(), count.end());
    printf("%d\n",apart);
    for(auto i : count) {
        printf("%d\n",i);
    }
}
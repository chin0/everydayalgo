#include <iostream>
#include <queue>
#include <utility>

using namespace std;

using loc = pair<int,int>;
int main(void)
{
    int m,n,value;
    queue<loc> q;

    cin >> m >> n;
    int map[n][m];

    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            cin >> map[i][j];
            if(map[i][j] == 1) q.push(loc(i,j));
        }
    }

    while(!q.empty()) {
        loc current = q.front();
        int y = current.first, x = current.second; 
        value = map[y][x];
        q.pop();
        if(y < n-1 && (map[y+1][x] == 0 || value + 1 < map[y+1][x])) { q.push(loc(y+1,x));map[y+1][x] = value + 1;};
        if(y > 0 && (map[y-1][x] == 0 || value + 1 < map[y-1][x])) { q.push(loc(y-1,x));map[y-1][x] = value + 1;};
        if(x < m-1 && (map[y][x+1] == 0 || value + 1 < map[y][x+1])) { q.push(loc(y,x+1)); map[y][x+1] = value + 1;};
        if(x > 0 && (map[y][x-1] == 0 || value + 1 < map[y][x-1])) { q.push(loc(y,x-1)); map[y][x-1] = value + 1;};
    }
    value -= 1;
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            if(map[i][j] == 0) { value = -1; break; }
        }
    }  
    cout << value << endl;
}


#include <queue>
#include <iostream>

using namespace std;

struct loc {
    int x;
    int y;
    int z;
    loc(int x,int y,int z) : x(x), y(y), z(z) { }
};

int main(void) {
    int value=1,m,n,h;
    queue<loc> q;

    cin >> m >> n >> h;
    int map[h][n][m];

    for(int i = 0; i < h; i++) {
        for(int j = 0; j < n; j++) {
            for(int k = 0; k < m; k++) {
                cin >> map[i][j][k];
                if(map[i][j][k] == 1)
                    q.push({k,j,i});
            }
        }
    }

    
    while(!q.empty()) {
        loc current = q.front();
        int x = current.x, y = current.y, z = current.z;
        value = map[z][y][x];
        q.pop();
        if(z < h-1 && (map[z+1][y][x] == 0 || value + 1 < map[z+1][y][x])) {map[z+1][y][x] = value + 1; q.push({x,y,z+1});};
        if(z > 0 && (map[z-1][y][x] == 0 || value + 1 < map[z-1][y][x])) {map[z-1][y][x] = value + 1; q.push({x,y,z-1});};
        if(y < n-1 && (map[z][y+1][x] == 0 || value + 1 < map[z][y+1][x])) {map[z][y+1][x] = value + 1; q.push({x,y+1,z});};
        if(y > 0 && (map[z][y-1][x] == 0 || value + 1 < map[z][y-1][x])) {map[z][y-1][x] = value + 1; q.push({x,y-1,z});};
        if(x < m-1 && (map[z][y][x+1] == 0 || value + 1 < map[z][y][x+1])) {map[z][y][x+1] = value + 1;q.push({x+1,y,z});};
        if(x > 0 && (map[z][y][x-1] == 0 || value + 1 < map[z][y][x-1])) {map[z][y][x-1] = value + 1; q.push({x-1,y,z});};
    }
    value--;
    for(int i = 0; i < h; i++) {
        for(int j = 0; j < n; j++) {
            for(int k = 0; k < m; k++) {
                if(map[i][j][k] == 0) {
                    value = -1; break;
                }
            }
        }
    }
    cout << value << endl;
}


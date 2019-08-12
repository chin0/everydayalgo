#include <iostream>
#include <queue>
using namespace std;
bool ans[201];
bool check[201][201];
int main() {
    int a, b, c;
    cin >> a >> b >> c;
    int sum = c;
    queue<pair<int,int>> q;
    q.push(make_pair(0, 0));
    check[0][0] = true;
    ans[c] = true;
    while (!q.empty()) {
        int x = q.front().first;
        int y = q.front().second;
        int z = sum - x - y;
        q.pop();
        int nx, ny, nz;
        nx = x;
        ny = y;
        nz = z;
        // x -> y
        ny += nx;
        nx = 0;
        if (ny >= b) {
            nx = ny-b;
            ny = b;
        }
        if (!check[nx][ny]) {
            check[nx][ny] = true;
            q.push(make_pair(nx,ny));
            if (nx == 0) {
                ans[nz] = true;
            }
        }

        nx = x;
        ny = y;
        nz = z;
        // x -> z
        nz += nx;
        nx = 0;
        if (nz >= c) {
            nx = nz-c;
            nz = c;
        }
        if (!check[nx][ny]) {
            check[nx][ny] = true;
            q.push(make_pair(nx,ny));
            if (nx == 0) {
                ans[nz] = true;
            }
        }

        nx = x;
        ny = y;
        nz = z;
        // y -> x
        nx += ny;
        ny = 0;
        if (nx >= a) {
            ny = nx-a;
            nx = a;
        }
        if (!check[nx][ny]) {
            check[nx][ny] = true;
            q.push(make_pair(nx,ny));
            if (nx == 0) {
                ans[nz] = true;
            }
        }

        nx = x;
        ny = y;
        nz = z;
        // y -> z
        nz += ny;
        ny = 0;
        if (nz >= c) {
            ny = nz-c;
            nz = c;
        }
        if (!check[nx][ny]) {
            check[nx][ny] = true;
            q.push(make_pair(nx,ny));
            if (nx == 0) {
                ans[nz] = true;
            }
        }

        nx = x;
        ny = y;
        nz = z;
        //z -> x
        nx += nz;
        nz = 0;
        if (nx >= a) {
            nz = nx-a;
            nx = a;
        }
        if (!check[nx][ny]) {
            check[nx][ny] = true;
            q.push(make_pair(nx,ny));
            if (nx == 0) {
                ans[nz] = true;
            }
        }

        nx = x;
        ny = y;
        nz = z;
        // z -> y
        ny += nz;
        nz = 0;
        if (ny >= b) {
            nz = ny-b;
            ny = b;
        }
        if (!check[nx][ny]) {
            check[nx][ny] = true;
            q.push(make_pair(nx,ny));
            if (nx == 0) {
                ans[nz] = true;
            }
        }
    }
    for (int i=0; i<=c; i++) {
        if (ans[i]) {
            cout << i << ' ';
        }
    }
    cout << '\n';
    return 0;
}

#include <iostream>
#include <queue>

using namespace std;

const int MAX = 200000;

bool check[MAX+1];
int dist[MAX+1];

int main() {
    int n,m;
    cin >> n >> m;
    check[n] = true;
    dist[n] = 0;

    queue<int> q;
    q.push(n);
    while(!q.empty()) {
        int now = q.front();
        q.pop();
        if(now-1 >= 0) {
            if(check[now-1] == false) {
                q.push(now-1);
                check[now-1] = true;
                dist[now-1] = dist[now]+1;
            }
        }
        if(now+1 < MAX) {
            if(check[now+1] == false) {
                q.push(now+1);
                check[now+1] = true;
                dist[now+1] = dist[now]+1;
            }
        }
        if(now*2 < MAX) {
            if(check[now*2] == false) {
                q.push(now*2);
                check[now*2] = true;
                dist[now*2] = dist[now]+1;
            }
        }
    }
    cout << dist[m] << endl;
    return 0;
}

#include <iostream>
#include <string>

using namespace std;

int dx[] = {1,-1,0,0,1,1,-1,-1};
int dy[] = {0,0,1,-1,1,-1,1,-1};


char map[5][5];
inline bool check(int x, int y)
{
    if(x >= 0 && x < 5 && y>= 0 && y <5) {
        return true;
    }
    return false;
}
bool solve(int cx, int cy, const string &word)
{
    if(!check(cx,cy)) return false;
    if(map[cx][cy] != word[0]) return false;
    if(word.size() == 1) return true;

    for(int dir = 0; dir < 8; dir++) {
        int x = cx + dx[dir];
        int y = cy + dy[dir];
        if(solve(x,y,word.substr(1)))
            return true;
    }
    return false;
}
int main(void)
{
    cin.tie(NULL);
    ios::sync_with_stdio(false);

    int c;
    cin >> c;
    for(int p = 0; p < c; p++) {
        for(int i = 0; i < 5; i++) {
            cin >> map[i];
        }

        int n;
        cin >> n;
        for(int i = 0; i < n; i++) {
            string dest;
            cin >> dest;
            bool ans = false;
            for(int j = 0; j < 5; j++) {
                for(int k = 0; k < 5; k++) {
                    if(map[j][k] == dest[0]) {
                        if(solve(j,k,dest)) {
                            ans = true;
                            break;
                        }
                    }
                }
            }
            cout << dest << ' ' << ans << '\n';
        }
    }
}

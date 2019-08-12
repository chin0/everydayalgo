#include <iostream>
using namespace std;
int parent[101];
int Find(int x) {
    if(x == parent[x]) {
        return x;
    } else {
        return parent[x] = Find(parent[x]);
    }
}

void Union(int x, int y) {
    x = Find(x);
    y = Find(y);
    if(x != y)
        parent[y] = x;
}

int main()
{
    int n,m;
    cin >> n >> m;
    for(int i = 1; i <= n; i++) {
        parent[i] = i;
    }

    while(m--) {
        int x, y;
        cin >> x >> y;
        Union(x,y);
    }

    int ans = 0;
    for(int i = 2; i <= n; i++) {
        if(Find(1) == Find(i)) {
            ans += 1;
        }
    }
    cout << ans << endl;
    return 0;
}

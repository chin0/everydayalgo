#include <cstdio>
#include <cstring>
#include <algorithm>

using namespace std;

int a[10001];
int d[10001][31];
int n,m;
//pos = 초
int go(int pos, int turn) {
    if(pos == n+1 && turn <= m) {
        return 0;
    }
    if(turn > m) {
        return 0;
    }
    if(d[pos][turn] != -1)
        return d[pos][turn];
    int where = turn % 2 + 1;
    int &ans = d[pos][turn];
    ans = max(go(pos+1,turn), go(pos+1,turn+1)) + (where == a[pos] ? 1 : 0);
    return ans;
}

int main()
{
    scanf("%d %d", &n, &m);
    for(int i =1; i <= n; i++)
        scanf("%d", &a[i]);
    memset(d,-1,sizeof(d));
    printf("%d\n",max(go(1,0),go(1,1)));
    return 0;
}

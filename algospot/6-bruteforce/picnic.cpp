#include <cstdio>
#include <cstring>
#include <vector>


//전체탐색 + 답의 정규화. 가장 빠른것부터 짝지어주면 순서문제가 해결됨.
// 매우 기초적인 문제.
using namespace std;

bool friends[10][10];

int solve(int n, bool selected[10]) {
    int notPaired = -1;

    for(int i = 0; i < n; i++) {
        if(!selected[i]){
            notPaired = i;
            break;
        }
    }

    if(notPaired == -1) return 1;
    int ans = 0;
    for(int i = 0; i < n; i++) {
        if(!selected[i] && friends[notPaired][i]) {
            selected[i] = selected[notPaired] = 1;
            ans += solve(n, selected);
            selected[i] = selected[notPaired] = 0;
        }
    }
    return ans;
}
int main(void)
{
    int c,n,m;
    
    scanf("%d", &c);
    for(int i = 0; i < c; i++) {
        scanf("%d %d", &n, &m);
        memset(friends, 0, sizeof(bool) * 100);
        for(int j = 0; j < m; j++) {
            int a,b;
            scanf("%d %d", &a, &b);
            friends[a][b] = true;
            friends[b][a] = true;
        }
        bool selected[10] = {false,};
        printf("%d\n", solve(n,selected));
    }
}
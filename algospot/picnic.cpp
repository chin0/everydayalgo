#include <cstdio>
#include <utility>
#include <cstring>

using namespace std;

bool isFriend[10][10];

//확실한건 짝을 지을수있는 경우에는 무조건 임의의 i의 친구가 항상 존재함.
int solve(bool state[], int n) {
    //짝이 지어지지 않은 가장 작은 인덱스 구하기.
    int first = -1;
    bool finished = true;
    for(int i = 0; i < n; i++) {
        if(!state[i]) {
            finished = false;
            first = i;
            break;
        }
    }
    if(finished) return 1;
    int cnt = 0;
    for(int second = first+1; second < n; second++) {
        if(!state[first] && !state[second] && isFriend[first][second]) {
            state[first] = state[second] = true;
            cnt += solve(state,n);
            state[first] = state[second] = false;
        }
    }
    return cnt;
}

int main(void)
{
    int c;
    scanf("%d", &c);

    for(int p = 0; p < c; p++) {
        int n,m;
        bool state[10];
        scanf("%d %d", &n, &m);
        memset(isFriend,0,sizeof(bool) * 100);
        memset(state, 0, sizeof(bool) * 10);
        for(int i = 0; i < m; i++) {
            int a,b;
            scanf("%d %d", &a, &b);
            isFriend[a][b] = true;
            isFriend[b][a] = true;
        }
        printf("%d\n", solve(state,n));
    }
}

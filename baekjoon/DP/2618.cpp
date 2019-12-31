#include <cstdio>
#include <vector>
#include <utility>
#include <stack>
#include <algorithm>

using namespace std;

using place = pair<int,int>;


int dist(const place &p1, const place &p2)
{
    return abs(p1.first - p2.first) + abs(p1.second - p2.second);
}
int w;
int n;
place events[1001];
// 정의는 dp[x][y] -> 1번차가 x, 2번차가 y번째 사건을 처리했을때 최소거리. 바텀업 구현이라서 구현상에서는 정의가 약간 다르긴 함.
int dp[1001][1001];
int back[1001];

//바텀업이라서 결과적으로 dp[0][0]에 최종값이 담김.
int search(int c1, int c2)
{
    if(c1 == w || c2 == w) return 0;
    int &ret = dp[c1][c2];
    if(ret != -1) return ret;

    int next = max(c1,c2) + 1;
    int c1_next;
    int c2_next;
    if(c1 == 0)
        c1_next = search(next, c2) + dist({1,1}, events[next]);
    else
        c1_next = search(next, c2) + dist(events[c1], events[next]);
    if(c2 == 0)
        c2_next = search(c1, next) + dist({n,n}, events[next]);
    else
        c2_next = search(c1, next) + dist(events[c2], events[next]);
    ret = min(c1_next, c2_next);
    return ret;
}

//걍 거꾸로 추적하면 쉬움. dp값은 이미 계산되었기 때문에.
void trace(int c1, int c2) {
    if(c1 == w || c2 == w) return;
    int next = max(c1,c2) + 1;
    int c1_next,c2_next;
    if(c1 == 0)
        c1_next = dp[next][c2] + dist({1,1}, events[next]);
    else
        c1_next = dp[next][c2] + dist(events[c1], events[next]);
    if(c2 == 0)
        c2_next = dp[c1][next] + dist({n,n}, events[next]);
    else
        c2_next = dp[c1][next] + dist(events[c2], events[next]);
    if(c1_next < c2_next) {
        back[next] = 1;
        trace(next,c2);
    } else {
        back[next] = 2;
        trace(c1,next);
    }
}
int main(void)
{
    memset(dp,-1,sizeof(dp));
    scanf("%d", &n);
    scanf("%d", &w);
    for(int i = 1; i <= w; i++) {
        scanf("%d %d", &events[i].first, &events[i].second);
    }
    printf("%d\n", search(0,0));
    trace(0,0);
    for(int i = 1; i <= w; i++) {
        printf("%d\n",back[i]);
    }
}


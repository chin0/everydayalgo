#include <cstdio>
#include <vector>
#include <utility>
#include <stack>
#include <algorithm>

//실패이유: 상당히 많은 경우의수를 빼먹음.
using namespace std;

using place = pair<int,int>;

typedef struct state
{
    long long cost;
    int from;
    place car1;
    place car2;
}state;

int distance(const place &p1, const place &p2)
{
    return abs(p1.first - p2.first) + abs(p1.second - p2.second);
}

state dp[2][1000];

int main(void)
{
    int w,n;
    vector<place> events;
    scanf("%d", &n);
    scanf("%d", &w);
    for(int i = 0; i < w; i++) {
        int tx, ty;
        scanf("%d %d", &tx, &ty);
        events.push_back({tx,ty});
    }
    dp[0][0] = {distance({1,1}, events[0]), -1, events[0], {n,n}};
    dp[1][0] = {distance({n,n}, events[0]), -1, {1,1}, events[0]};

    for(int i = 1; i < w; i++) {
        int car1_cost = distance(dp[0][i-1].car1, events[i]) + dp[0][i-1].cost;
        int car2_cost = distance(dp[1][i-1].car1, events[i]) + dp[1][i-1].cost;
        if(car1_cost < car2_cost) {
            dp[0][i] = {car1_cost, 0,events[i], dp[0][i-1].car2};
        } else {
            dp[0][i] = {car2_cost, 1, events[i], dp[1][i-1].car2};
        }

        car1_cost = distance(dp[0][i-1].car2, events[i]) + dp[0][i-1].cost;
        car2_cost = distance(dp[1][i-1].car2, events[i]) + dp[1][i-1].cost;
        if(car1_cost < car2_cost) {
            dp[1][i] = {car1_cost, 0,dp[0][i-1].car1, events[i]};
        } else {
            dp[1][i] = {car2_cost, 1, dp[1][i-1].car1,events[i]};
        }
    }

    for(int i = 0; i < 2; i++) {
        for(int j = 0; j < w; j++) {
            printf("(%lld,%d) ", dp[i][j].cost,dp[i][j].from);
        }
        printf("\n");
    }
    stack<int> s;
    int cur = 1;
    if(dp[0][w-1].cost < dp[1][w-1].cost) {
        cur = 0;
    }
    printf("%lld\n",dp[cur][w-1].cost);
    for(int i = w-1; i >= 0; i--) {
        s.push(cur);
        cur = dp[cur][i].from;
    }
    while(!s.empty()) {
        printf("%d\n",s.top()+1);
        s.pop();
    }
}


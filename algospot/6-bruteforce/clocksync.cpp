#include <cstdio>
#include <vector>
#include <algorithm>

using namespace std;

// 완전탐색에서 무한한 경우의 수를 문제를 잘 관찰해서 유한한 경우의 수로 바꿔야함.
// 여기에선 버튼을 누르는 순서는 상관이 없고 4번 누르면 같기 때문에 각 버튼은 0~3번만 눌러야 최적임.

vector<int> connected[10] = { 
    {0,1,2},
    {3,7,9,11},
    {4,10,14,15},
    {0,4,5,6,7},
    {6,7,8,10,12},
    {0,2,14,15},
    {3,14,15},
    {4,5,7,14,15},
    {1,2,3,4,5},
    {3,4,5,9,13}
};

bool isAligned(const vector<int>& clocks) {
    bool ok = true;
    for(int i = 0; i < clocks.size(); i++) {
        if(clocks[i] != 12) {
            ok = false;
            break;
        }
    }
    return ok;
}

int INF = 1 << 30;
//t번 스위치를 누른다.
void push(vector<int>& clocks, int t) {
    for(int i = 0; i < connected[t].size(); i++){
        int &current = clocks[connected[t][i]];
        current += 3;
        if(current == 15) current = 3;
    }
}

int solve(vector<int> &clocks, int t) {
    if(t == 10) return isAligned(clocks) ? 0 : INF;
    int ret = INF;
    for(int cnt = 0; cnt < 4; ++cnt) {
        ret = min(ret, cnt + solve(clocks, t+1));
        push(clocks,t);
    }
    //4번을 다 눌렀으므로 clock은 원래 상태.
    return ret;
}
int main(void)
{
    int c;
    scanf("%d", &c);
    while(c--) {
        int temp;
        vector<int> clock;
        for(int i = 0; i < 16; i++) {
            scanf("%d", &temp);
            clock.push_back(temp);
        }
        printf("%d\n", solve(clock,0));
    }
}
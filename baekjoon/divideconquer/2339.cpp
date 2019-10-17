#include <cstdio>
#include <tuple>
#include <vector>

//아싸 대충 구현했는데 맞음.
using namespace std;

using position = pair<int,int>;
//(불순물, 보석), 불순물 좌표들
using cnt_result = pair<pair<int,int>, vector<position>>;

int map[20][20];
vector<pair<int,int>> jew;
vector<pair<int,int>> imp;

// 구간의 왼쪽 위, 오른쪽 아래
cnt_result count_stone(position p1, position p2) {
    int x1,x2,y1,y2;
    tie(x1,y1) = p1;
    tie(x2,y2) = p2;
   
    int stone = 0, jewel = 0;
    vector<position> stone_position;
    for(auto i : imp) {
        int imp_x, imp_y;
        tie(imp_x,imp_y) = i;
        if(x1 <= imp_x && imp_x < x2 && y1 <= imp_y && imp_y < y2) {
            stone++;
            stone_position.push_back({imp_x, imp_y});
        }
    }
    for(auto i : jew) {
        int jew_x, jew_y;
        tie(jew_x, jew_y) = i;
        if(x1 <= jew_x && jew_x < x2 && y1 <= jew_y && jew_y < y2) {
            jewel++;
        }
    }
    return {{stone,jewel},stone_position};
}
// dir = 0 가로 dir = 1 세로,초기 = 2  
int solve(position p1, position p2, int dir)
{
    cnt_result cnt = count_stone(p1, p2);
    //printf("(%d %d), (%d %d) %d: %d %d\n", p1.first, p1.second, p2.first, p2.second,dir, cnt.first.first, cnt.first.second);
    //보석이 포함되어있지 않은 경우.
    if(cnt.first.second == 0) return 0;
    //불순물을 다 걸렀는데 보석이 1개 이상 포함되어있는 경우.
    if(cnt.first.first == 0 && cnt.first.second > 1) return 0;
    //불순물을 다 걸러서 보석이 영역내에 딱 하나 남은경우.
    if(cnt.first.first == 0 && cnt.first.second == 1) return 1;

    vector<position> stone_pos = cnt.second;
    int ans = 0;
    for(auto i : stone_pos) {
        int x = i.first;
        int y = i.second;
        if((dir == 2 || !dir) && x > 0 && x < p2.first) {
            ans += solve(p1, {x,p2.second},1) * solve({x+1, p1.second}, p2, 1);
        }
        if((dir == 2 || dir)  && y > 0 && y < p2.second) {
            ans += solve(p1, {p2.first,y},0) * solve({p1.first,y+1}, p2, 0);
        }
    }
    return ans;
}

int main(void)
{
    int n;
    scanf("%d", &n);
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            scanf("%d", &map[i][j]);
            if(map[i][j] == 1) imp.push_back({j,i});
            if(map[i][j] == 2) jew.push_back({j,i});
        }
    }
    int ans =0;
    ans += solve({0,0},{n,n}, 2);
    if(ans == 0) {
        ans = -1;
    }
    printf("%d\n",ans);
}

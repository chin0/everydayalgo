#include <utility>
#include <vector>
#include <cstdio>

using namespace std;

pair<int,int> count_strike_ball(int a, int b) {
    int ball = 0, strike = 0;
    for(int i = 1; i <= 100; i *= 10) {
        int cur_a = a / i % 10;
        for(int j = 1; j <= 100; j *= 10 ) {
            int cur_b = b / j % 10;
            if(cur_a == cur_b) {
                if(i == j) strike++;
                else ball++;
                break;
            }
        }
    }

    return make_pair(strike, ball);
}

int main(void) {
    int n;
    int ans=0;
    vector<pair<int,int>> qcount;
    vector<int> qn;
    scanf("%d", &n);
    for(int i = 0; i < n; i++) {
        int n, first, second;
        scanf("%d %d %d",&n, &first, &second);
        qcount.push_back(make_pair(first,second));
        qn.push_back(n);
    }

    for(int f = 1; f < 10; f++) {
        for(int s = 1; s < 10; s++) {
            if(f == s) continue;
            for(int t = 1; t < 10; t++) {
                if(s == t || t == f) continue;
                int current = f * 100 + s * 10 + t;
                bool is_correct = true;
                for(int j = 0; j < n; j++) {
                    auto p = count_strike_ball(qn[j], current);
                    if(qcount[j] != p){
                        is_correct = false;
                        break;
                        }
                    }
                if(is_correct) ans++;
            }
        }
    }
    printf("%d\n", ans);
}
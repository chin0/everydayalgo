#include <cstdio>
#include <vector>
#include <algorithm>

using namespace std;

int score[20][20];

inline int abs(int a) {
    return (a < 0) ? -a : a;
}
int main(void)
{
    int n;
    scanf("%d", &n);
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++)
            scanf("%d", &score[i][j]);
    }
    vector<int> comb;

    for(int i = 0; i < n/2; i++) {
        comb.push_back(0);
    }
    for(int i = 0; i < n/2; i++) {
        comb.push_back(1);
    }

    int min = 2147483647;
    do{
        vector<int> start,link;
        for(int i = 0; i < n; i++) {
            if(comb[i]) start.push_back(i);
            else link.push_back(i);
        }

        int start_sum = 0, link_sum = 0;
        for(int i = 0; i < n/2; i++) {
            for(int j = i+1; j < n/2; j++) {
                start_sum += score[start[i]][start[j]];
                start_sum += score[start[j]][start[i]];
                link_sum += score[link[i]][link[j]];
                link_sum += score[link[j]][link[i]];
            }
        }
        if(min > abs(start_sum - link_sum)) {
            min = abs(start_sum - link_sum);
        }
    }while(next_permutation(comb.begin(), comb.end()));
    printf("%d\n",min);
}

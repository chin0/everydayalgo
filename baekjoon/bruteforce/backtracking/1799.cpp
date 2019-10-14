#include <cstdio>

bool check1[50];
bool check2[50];
int map[10][10];

int n;
int solve(int cur) {
    if(n == 1 && cur == 1) {
        return cur;
    } else if(n > 1) {
        if(cur == 2 * (n-1)) {
            return cur;
        }
    }
    int m = 0;
    bool found = false;
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            if(!check1[j+i] && !check2[n-j+i] && map[i][j]) {
                found = 1;
                check1[j+i] = true;
                check2[n-j+i] = true;
                map[i][j] = 0;
                int ret = solve(cur+1);
                if(ret > m) m = ret;
                check1[j+i] = false;
                check2[n-j+i] = false;
                map[i][j] = 1;
            }
        }
    }
    if(!found) return cur;
    return m;
}
int main(void)
{
    scanf("%d", &n);
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            scanf("%d", &map[i][j]);
        }
    }

    printf("%d\n", solve(0));
}

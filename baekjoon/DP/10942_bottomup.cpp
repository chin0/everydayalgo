#include <cstdio>
int n;
int a[2000];
bool d[2000][2000];
int main()
{
    scanf("%d", &n);
    for(int i = 0; i < n; i++) {
        scanf("%d", &a[i]);
    }
    for(int i = 0; i < n; i++) {
        d[i][i] = true;
    }
    for(int i = 0; i < n-1; i++) {
        if(a[i] == a[i+1])
            d[i][i+1] = true;
    }
    for(int k = 3; k <= n; k++) {
        for(int i = 0; i <= n-k; i++) {
            int j = i+k-1;
            if(a[i] == a[j] && d[i+1][j-1]) {
                d[i][j] = true;
            }
        }
    }
    int m;
    scanf("%d", &m);
    while(m--) {
        int s,e;
        scanf("%d %d", &s, &e);
        printf("%d\n", d[s-1][e-1]);
    }
}

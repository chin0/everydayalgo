#include <cstdio>

int d[1001][1001];

int main(void)
{
    int n,k;
    scanf("%d %d", &n, &k);

    for(int i = 0; i <= n; i++) { //i == 0일때는 0개중에 0개를 뽑는경우도 있으니 이 경우도 체크해줘야함.
        d[i][0] = d[i][i] = 1;
        for(int j = 1; j <= i-1; j++) {
            d[i][j] = d[i-1][j-1] + d[i-1][j];
            d[i][j] %= 10007;
        }
    }
    printf("%d\n",d[n][k]);
}

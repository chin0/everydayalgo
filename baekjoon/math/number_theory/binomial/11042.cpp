//뤼카의 정리
#include <cstdio>

int d[2001][2001];

int main(void)
{
    long long n,k,m;
    scanf("%lld %lld %lld", &n, &k, &m);
    for(int i = 0; i <= m; i++) {
        d[i][0] = d[i][i] = 1;
        for(int j = 1; j <= i-1; j++) {
            d[i][j] = (d[i-1][j-1] + d[i-1][j])%m;
        }
    }

    int ans = 1;
    while(n) {
        ans *= d[n%m][k%m];
        ans %= m;
        n /= m;
        k /= m;
    }

    printf("%d\n",ans);
}

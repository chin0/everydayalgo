//그리디하게 생각해보면 최대한 5짜리로 많이 담는게 좋음.
// 5짜리로 최대한 많이 담아보고 5를 하나씩 줄여가면서 3으로 나누어 떨어지는지 확인해보자.

#include <cstdio>
int main(void)
{
    int n,ans;
    scanf("%d",&n);

    ans = n / 5;
    n = n % 5;
    while(n % 3 != 0 && ans >= 0) {
        ans -= 1;
        n += 5;
    }
    if(ans == -1) {
        printf("%d\n",ans);
    } else {
        printf("%d\n", ans + n/3);
    }
}

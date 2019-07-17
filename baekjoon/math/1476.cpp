//중국인의 나머지 정리.
#include <cstdio>
#include <tuple>

using namespace std;

int main(void)
{
    int a1,a2,a3,m = 15 * 28 * 19;

    scanf("%d %d %d", &a1,&a2,&a3);

    int ans = a1 * 6916;
    ans += a2 * 4845 ;
    ans += a3 * 4200;
    ans %= m;
    //입력의 최대값에 의하여 m은 최대 15 * 28 * 19가 되는데 이때 %=m하면 0되므로 따로 처리 필요.
    if(ans == 0) ans = m;
    printf("%d\n",ans);
}



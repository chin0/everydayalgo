//문제를 푸는 과정을 세분화 시킨후 분할정복으로 풀면 댐.
#include <cstdio>

void solve(int n , int x, int y)
{
    if(n == 0) return;
    solve(n-1, x, 6-x-y);
    printf("%d %d\n", x,y);
    solve(n-1, 6-x-y,y);
}

//이동횟수는 점화식으로 구할수있음. 아니면 상식으로 하던가
int main(void)
{
    int n;
    scanf("%d",&n);
    printf("%d\n",(1<<n)-1);
    solve(n,1,3);
}

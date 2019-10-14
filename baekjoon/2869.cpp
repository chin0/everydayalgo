#include <cstdio>

int main(void)
{
    int a,b,v;

    scanf("%d %d %d", &a, &b, &v);

    int ans = (v- b) / (a-b);
    if((v-b) % (a-b)) ans += 1;
    printf("%d\n",ans);
}

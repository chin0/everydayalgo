#include <cstdio>

int main(void)
{
    int k,n,a[10],ans=0;

    scanf("%d %d", &n, &k);

    for(int i = 0; i < n; i++) {
        scanf("%d",&a[i]);
    }

    //a_1이 1이므로 무조건 다 거슬러줄수있음.
    for(int i = n-1; i >= 0; i--){
        ans += (k/a[i]);
        k %= a[i];
    }
    printf("%d\n",ans);
}

#include <cstdio>

using namespace std;

int a[10000];
int main(void)
{
    int n,m;

    scanf("%d %d", &n, &m);

    for(int i = 0; i < n; i++) {
        scanf("%d", &a[i]);
    }

    int sum = a[0];
    int left = 0, right = 0;
    int ans = 0;
    while(right < n) {
        if(sum < m) {
            right += 1;
            sum += a[right];
        } else if(sum == m) {
            ans += 1;
            right += 1;
            sum += a[right];
        } else if(sum > m) {
            sum -= a[left];
            left += 1;
        }
    }
    printf("%d\n",ans);
}

#include <cstdio>

int a[100000];

int main()
{
    int n,s;
    int ans = 10000000;

    scanf("%d %d", &n, &s);

    for(int i = 0; i < n; i++) {
        scanf("%d", &a[i]);
    }

    int left=0, right = 0;
    int sum = a[0];
    while(left <= right && right < n) {
        printf("%d %d\n", left, right);
        if(sum < s) {
            right++;
            sum += a[right];
        }else if(sum == s) {
            int len = right - left;
            if(ans > len)
                ans = len;
            right++;
            sum += a[right];
        } else {
            int len = right - left;
            if(ans > len)
                ans = len;
            sum -= a[left];
            left++;
        }
    }
    if(ans == 10000000)
        printf("0\n");
    else
        printf("%d\n", ans+1);
}

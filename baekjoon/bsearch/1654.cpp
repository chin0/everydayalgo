#include <cstdio>
long long a[100000];
int n,m;

bool check(long long x)
{
    int cnt = 0;
    for(int i = 0; i < n; i++) {
        cnt += a[i]/x;
    }
    return cnt >= m;
}

int main() {
    scanf("%d %d", &n, &m);
    long long max = 0;
    for(int i  = 0; i < n; i++) {
        scanf("%lld", &a[i]);
        if(max < a[i]) {
            max = a[i];
        }
    }

    long long ans = 0;
    long long l = 1;
    long long r = max;
    while(l <= r) {
        long long mid = (l+r)/2;
        if(check(mid)) {
            if(ans < mid) {
                ans = mid;
            }
            l = mid+1;
        } else {
            r = mid-1;
        }
    }
    printf("%lld\n", ans);
    return 0;
}

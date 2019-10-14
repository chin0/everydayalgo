//분할정복법: 히스토그램 문제와 매우 유사.
// 1. 왼쪽부분이 최댓값.
// 2. 오른쪽부분이 최댓값.
// 3. 왼쪽이랑 오른쪽 걸쳐있음. (가운데부터 큰 수부터 합치면서 하면 최댓값을 쉽게 구할수있음. 그리디하게.)
#include <cstdio>
#include <algorithm>

using namespace std;

using ll = long long;

ll a[100000],sum[100000];

ll solve(int s,int e)
{
    if(s == e) return a[s] * a[s];
    int mid = (s+e) / 2;
    ll result = max(solve(s,mid),solve(mid+1, e));
    int l=mid,r=mid+1;
    ll m=min(a[l],a[r]);
    result = max((a[l] + a[r]) * m, result);

    while(s < l || r < e) {
        if(s == l || (r < e && a[r+1] > a[l-1])) m=min(m,a[++r]);
        else m = min(m, a[--l]);

        result = max(result, (sum[r] - sum[l-1]) * m);
    }
    return result;
}
int main(void)
{
    int n;
    scanf("%d", &n);

    for(int i = 0; i < n; i++) {
        scanf("%lld", &a[i]);
    }
    sum[0] = a[0];
    for(int i = 1; i < n; i++) sum[i] = a[i] + sum[i-1];
    printf("%lld\n",solve(0,n-1));
}

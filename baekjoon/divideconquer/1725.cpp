#include <cstdio>
#include <algorithm>

using namespace std;

int h[100000];

int solve(int s, int e)
{
    if(s == e) return h[s];

    int mid = (s+e)>>1;
    int result = max(solve(s,mid), solve(mid+1,e));
    int l = mid, r=mid+1;
    int m = min(h[l],h[r]);
    result = max(2 * m, result);
    while(s < l || r < e) {
        if(s == l || (r < e && h[r+1] >= h[l-1])) m = min(m, h[++r]);
        else m = min(m,h[--l]);
        result = max((r-l+1) * m, result);
    }
    return result;
}
int main(void)
{
    int n;
    scanf("%d", &n);
    for(int i = 0; i < n; i++) scanf("%d", &h[i]);
    printf("%u\n",solve(0,n-1));
}

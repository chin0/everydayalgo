#include <vector>
#include <cstdio>
#include <algorithm>

using namespace std;

int solve(const vector<int> &h, int left, int right) 
{
    //base case;
    if(left == right) return h[left];

    int mid = (left + right) / 2;
    int ret = max(solve(h,left, mid), solve(h,mid+1, right));

    // 중간에 걸친 케이스.
    int lo = mid, hi = mid + 1;
    int height = min(h[lo], h[hi]);

    ret = max(ret, height * 2);

    while(left < lo || hi < right) {
        if(hi < right && (lo == left || h[lo-1] < h[hi+1])) {
            ++hi;
            height = min(height, h[hi]);
        } else {
            --lo;
            height = min(height, h[lo]);
        }
        ret = max(ret, height * (hi - lo + 1));
    }
    return ret;
}

int main(void)
{
    int c;
    scanf("%d" , &c);
    while(c--) {
        int n;
        vector<int> v;
        scanf("%d", &n);
        for(int i = 0; i < n; i++) {
            int temp;
            scanf("%d", &temp);
            v.push_back(temp);
        }
        printf("%d\n", solve(v,0, n-1));
    }
}
#include <cstdio>
#include <vector>
#include <algorithm>

using namespace std;


typedef long long int ull;
ull N,H[100000];
//분할정복으로 히스토그램 문제 풀이.
// 중요한건 얘는 가운데부터 확장해나간다고 생각해야함.
ull histogram(int s, int e) {
    //base case
    if(s == e) return 0; //넓이 0
    if(s+1 == e) return H[s]; //넓이 1

    int mid = (s+e)/2;
    ull result = max(histogram(s,mid), histogram(mid,e));


    ull w = 1, h = H[mid], l = mid, r = mid;
    while(r-l+1 < e-s) {
        ull p = l>s ? min(h,H[l-1]) : -1;
        ull q= r<e-1 ? min(h,H[r+1]) : -1;

        if(p >= q) {
            h = p;
            l--;
        } else {
            h = q;
            r++;
        }
        result = max(result, ++w*h);
    }
    return result;
}

int main()
{
    while(1) {
        scanf("%lld", &N);
        if(N==0) return 0;
        for(int i = 0; i < N; i++) {
            scanf("%lld", &H[i]);
        }
        printf("%lld\n", histogram(0,N));
    }
}

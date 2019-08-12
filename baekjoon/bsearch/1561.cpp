#include <iostream>

using namespace std;

int a[10000];
int p,n;

int main()
{
    cin >> p >> n;
    for(int i = 0; i < n; i++)
        cin >> a[i];
    if(p <= n){
        printf("%d\n",p);
        return 0;
    }

    long long left = 0;
    long long right = 2000000000LL * 1000000LL; //걍 임의로 크게 잡은것.
    while(left <= right) {
        long long mid = (left + right) / 2;
        long long begin, end;
        begin=end=0;
        end = n;
        for(int i = 0; i < n; i++) {
            end += mid/a[i];
        }
        begin = end;
        for(int i = 0; i < n; i++) {
            if(mid %a[i] == 0) {
                begin -= 1;
            }
        }
        begin += 1;
        if(p < begin) {
            right = mid - 1;
        } else if(p > end) {
            left = mid + 1;
        } else {
            for(int i = 0; i < n; i++) {
                if(mid % a[i] == 0) {
                    if(p == begin) {
                        printf("%d\n", i+1);
                        return 0;
                    }
                    begin += 1;
                }
            }
        }
    }
}

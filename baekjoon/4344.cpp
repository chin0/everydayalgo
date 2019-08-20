#include <cstdio>
#include <vector>

using namespace std;

int main(void)
{
    int c;
    scanf("%d", &c);
    for(int i = 0; i < c; i++) {
        int n;
        double total=0, result=0;
        scanf("%d", &n);
        vector<int> a(n);
        for(int i = 0; i < n; i++) {
            scanf("%d", &a[i]);
            total += a[i];
        }
        total /= (double)n;
        for(int i = 0; i < n; i++) {
            if(a[i] > total) {
                result += 1;
            } 
        }
        result = (double)result / (double)n * 100;
        printf("%.3lf%%\n",result);
    }
}

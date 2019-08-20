#include <cstdio>
#include <vector>
#include <algorithm>

using namespace std;

int main(void)
{
    int n;
    scanf("%d", &n);

    vector<double> a(n);
    for(int i = 0 ; i < n; i++) {
        int temp;
        scanf("%d",&temp);
        a[i] = (double)temp;
    }

    double m = *max_element(a.begin(), a.end());
    double result = 0;
    for(auto i : a) {
        result += i/m * 100;
    }
    printf("%lf\n", result/n);
}

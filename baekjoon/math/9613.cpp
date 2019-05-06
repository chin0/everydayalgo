#include <cstdio>

using namespace std;

int gcd(int a, int b) {
    if(b > a) {
        return gcd(b,a);
    }
    if(b == 0) 
        return a;
    return gcd(b, a%b);
}

int main(void)
{
    int t,n;
    int num[101];
    scanf("%d", &t);
    for(int i = 0; i < t; i++) {
        scanf("%d", &n);
        for(int j = 0; j < n; j++) {
            scanf("%d", &num[j]);
        }
        
        unsigned long long int sum = 0;
        for(int j = 0; j < n; j++) {
            for(int k = j+1; k < n; k++) {
                sum += gcd(num[j],num[k]);
            }
        }
        printf("%llu\n",sum);
    }
}
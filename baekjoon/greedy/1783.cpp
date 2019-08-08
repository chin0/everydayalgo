//높이를 기준으로 경우를 나누어 생각.
#include <cstdio>

using namespace std;

typedef unsigned long long int ull;

int main(void)
{
    ull n, m,result;

    scanf("%llu %llu",&n,&m);

    result = 0;
    if(n == 1) {
        result = 1;
    } else if(n == 2) {
        result = (4 > (m+1)/2) ? (m+1)/2 : 4;
    } else if(n >= 3) {
        if(m >= 7) {
            result = m - 2;
        } else {
            result = (4 > m) ? m : 4;
        }
    }
    printf("%llu\n",result);
}

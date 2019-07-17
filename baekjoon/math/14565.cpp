// 모듈러 역원 구하는

#include <tuple>
#include <cstdio>

typedef long long int ull;

using namespace std;

//걍 외우는것도 ㄱㅊ 
tuple<ull,ull,ull> egcd(ull a, ull b)
{
    if(b == 0)
        return make_tuple(a,1,0);
    ull g,x,y;
    tie(g,x,y) = egcd(b,a%b);
    return make_tuple(g,y,x-(a/b)*y);
}

int main(void)
{
    ull n,a, ainv, minv;
    scanf("%lld %lld",&n,&a);
    ainv = n - a;
    tuple<ull,ull,ull> res = egcd(a,n);
    if(n%get<0>(res) == 0 && get<0>(res) != 1)
        minv = -1;
    else {
        minv = get<1>(res);
        //minv = minv > 0 ? minv : n + minv;
    }
    printf("%lld %lld\n", ainv, minv);
}

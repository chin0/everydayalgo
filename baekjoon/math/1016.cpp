//에라토스테네스의 채 응용
//제곱수를 발견하면 제곱수의 배수를 날려버리자.
//min,max와의 차가 1000000밖에 안되므로 min~max를 0~1000000에 대치시켜서 풀어야함.

#include <cstdio>
bool check[1000001];
long long min, max;

int main()
{
    scanf("%lld %lld", &min, &max);
    for(long long i = 2; i*i <= max; i++) {
        //
        long long start = i*i-min%(i*i); //min~max사이의 가장 작은 i*i의 배수
        if(start == i*i)
            start = 0;
        for(long long j = start; j <= max-min; j+=i*i)
            check[j] = true;
    }
    int ans = 0;
    for(int i =0; i <= max-min; i++) {
        if(check[i] == 0)
            ans++;
    }
    printf("%d\n",ans);
}

//팩토리얼의 0의 개수 세는거 응용해서 풀면 댐.
// nCk를 소인수분해하는건 n!, n-k!, k!를 소인수분해하는거와 같으니 쉽게 풀수있음.
// n이하의 소수에 대하여 nCk의 소인수의 개수를 세어준다음에 곱해주고 나머지 하면 댐.. 
#include <iostream>
#include <vector>

using namespace std;

long long cnt(long long n, long long p)
{
    long long k = 0;
    while(n > 0) {
        k += n / p;
        n /= p;
    }
    return k;
}

long long pow(long long a, long long b, long long mod) {
    long long x = 1, y = a;
    while(b > 0) {
        if((b&1) == 1) {
            x *= y;
            x %= mod;
        }
        y *= y;
        y %= mod;
        b /= 2;
    }
    return x;
}

long long c(long long n, long long m, long long mod) {
    long long ans = 1;
    vector<bool> check(n+1, true);
    for(long long i = 2; i <= n; i++) {
        if(check[i]) {
            for(long long j = 2*i; j<= n; j+=i)
                check[j] = false;
            long long k = cnt(n,i) - cnt(m,i) - cnt(n-m,i);
            ans = ans * pow(i,k,mod);
            ans = ans % mod;
        }
    }
    return ans;
}

int main()
{
    long long n,m,k;
    cin >> n >> m >> k;
    printf("%lld\n",c(n,m,k));
}

#include <stack>
#include <cstdio>

using namespace std;

using ll = long long int;

int main(void)
{
    ll n;
    stack<int> s;
    scanf("%lld", &n);
    if(n == 0) {
        printf("%d",0);
    }
    while(n) {
        ll quot = n / (-2);
        if(n % -2 < 0) {
            quot += 1;
            s.push(-(n % 2));
        }  else {
            s.push(n % -2);
        }
        n = quot;
    }

    while(!s.empty()) {
        printf("%d", s.top());
        s.pop();
    }
    
    printf("\n");
}
#include <cstdio>
#include <stack>

using namespace std;

int main(void)
{
    int k,n;
    scanf("%d", &k);
    stack<int> s;

    for(int i = 0; i < k; i++) {
        scanf("%d", &n);
        if(n == 0)
            s.pop();
        else
            s.push(n);
    }
    long long sum = 0;
    while(!s.empty()) {
        sum += s.top();
        s.pop();
    }
    printf("%lld\n", sum);
}

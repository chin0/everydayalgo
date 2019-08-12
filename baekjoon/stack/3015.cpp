#include <cstdio>
#include <stack>
#include <utility>

using namespace std;

int n;
int a[500000];
int main()
{
    scanf("%d", &n);
    for(int i = 0; i < n; i++)
        scanf("%d", &a[i]);

    stack<pair<int,int>> s;
    long long ans = 0;
    for(int i = 0; i < n; i++) {
        pair<int,int> p = {a[i],1};
        while(!s.empty()) {
            if(s.top().first <= a[i]) {
                ans += (long long)s.top().second;
                if(s.top().first == a[i])
                    p.second += s.top().second;
                s.pop();
            } else {
                break;
            }
        }
        if(!s.empty()) ans += 1;
        s.push(p);
    }
    printf("%lld\n",ans);
}

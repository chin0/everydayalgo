#include <queue>
#include <cstdio>
using namespace std;

int main()
{
    int n;
    priority_queue<int> q;

    scanf("%d",&n);
    while(n--) {
        int x;
        scanf("%d",&x);
        if(x == 0) {

            printf("%d\n",q.empty() ? 0 : q.top());
            if(!q.empty()) {
                q.pop();
            }
        } else {
            q.push(x);
        }
    }
    return 0;
}

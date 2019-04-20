#include <cstdio>
#include <vector>
#include <cmath>
#include <stack>

using namespace std;

int main(void)
{
    bool is_solvable = true;
    int current = 1,n,t;
    vector<char> v;
    stack<int> s;
    scanf("%d",&n);
    s.push(0);

    for(int i = 0; i < n; i++) {
        scanf("%d",&t);
        if(is_solvable) {
            if(s.top() < t) {
                while(s.top() != t){
                    s.push(current++);
                    v.push_back('+');
                }
                s.pop();
                v.push_back('-');
            } else {
                if(s.top() != t)
                    is_solvable = false;
                else
                {
                    v.push_back('-');
                    s.pop();
                }
            }
        }
    }
    if(is_solvable)
        for(int i = 0; i < v.size(); i++)
            printf("%c\n",v[i]);
    else
        printf("NO\n");
}
#include <cstdio>
#include <stack>
using namespace std;

char a[600000];

//커서를 기준으로 왼쪽 스택, 오른쪽 스택으로 두고 풀면 된다.
// 굉장히 기발한 아이디어다.
//모든 연산을 O(1)로 풀수있다.
int main()
{
    scanf("%s",a);

    int m;
    stack<char> left, right;

    int n = strlen(a);

    for(int i = 0; i < n; i++) {
        left.push(a[i]);
    }

    scanf("%d",&m);
    for(int i = 0 ; i < m; i++) {
        char what;
        scanf(" %c",&what);
        if(what == 'L') {
            if(!left.empty()) {
                right.push(left.top());
                left.pop();
            }
        } else if(what == 'D') {
            if(!right.empty()) {
                left.push(right.top());
                right.pop();
            }
        } else if(what == 'B') {
            if(!left.empty()) {
                left.pop();
            }
        } else if(what == 'P') {
            char c;
            scanf(" %c", &c);
            left.push(c);
        }
    }
    while(!left.empty()) {
        right.push(left.top());
        left.pop();
    }
    while(!right.empty()) {
        printf("%c",right.top());
        right.pop();
    }
}

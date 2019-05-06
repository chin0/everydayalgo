#include <stack>
#include <cstdio>
using namespace std;

int main(void) {
    stack<int> s;
    int n,b;
    scanf("%d %d", &n, &b);
    while(n) {
        s.push(n%b);
        n /= b;
    }
    while(!s.empty()) {
        int temp = s.top();
        s.pop();
        if(temp >= 10) {
            printf("%c",'A' + (temp-10));
        } else {
            printf("%d", temp);
        }
    }
    printf("\n");
}
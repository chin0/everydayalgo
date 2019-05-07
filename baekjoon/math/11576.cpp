#include <stdio.h>
#include <stack>
#include <cmath>

using namespace std;

int main(void)
{
    stack<int> s;
    int decimal=0,a,b,m,r = 1;

    scanf("%d %d", &a, &b);
    scanf("%d",&m);
    for(int i = 1; i < m; i++) {
        r *= a;
    }
    for(int i = 0; i < m; i++) {
        int temp;
        scanf("%d", &temp);
        decimal += r * temp;
        r /= a;
    }
    while(decimal) {
        s.push(decimal % b);
        decimal /= b;
    }
    while(!s.empty()) {
        printf("%d ", s.top());
        s.pop();
    }
    printf("\n");
}
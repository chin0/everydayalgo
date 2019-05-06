#include <stdio.h>

int gcd(int a, int b) {
    if(b > a) {
        return gcd(b,a);
    }
    if(b == 0) 
        return a;
    //printf("%d\n", a%b);
    return gcd(b, a%b);
}

int main(void) {
    int n;
    scanf("%d", &n);
    for(int i = 0; i < n; i++) {
        int a,b;
        scanf("%d %d", &a, &b);
        printf("%d\n",(a*b)/gcd(a,b));
    }
}
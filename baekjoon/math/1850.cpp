#include <stdio.h>

typedef unsigned long long int ull;
ull gcd(ull a, ull b) {
    if(b > a) {
        return gcd(b,a);
    }
    if(b == 0) 
        return a;
    return gcd(b, a%b);
}

int main(void)
{
    ull a,b;
    scanf("%llu %llu", &a, &b);
    ull result = 0;
    ull r = 1;
    for(int i = 0; i < gcd(a,b); i++) {
        printf("%d",1);
    }
    printf("\n");
}
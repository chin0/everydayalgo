#include <cstdio>

int main()
{
    int a,b;
    scanf("%d", &a);
    scanf("%d", &b);
    int c = a*b;
    while(b) {
        printf("%d\n", a * (b%10));
        b /= 10;
    }
    printf("%d\n", c);
}

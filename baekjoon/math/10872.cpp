#include <cstdio>

int factorial(int n) {
    if(n <= 1) return 1;
    return n * factorial(n-1);
}

int main(void)
{
    int n;
    scanf("%d",&n);
    printf("%d\n",factorial(n));
}
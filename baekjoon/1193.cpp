#include <iostream>

int main(void)
{
    int n;
    scanf("%d", &n);

    int sum = 1;
    while(n > sum) {
        n -= sum;
        sum += 1;
    }
    int ja = sum % 2 ? sum-n+1 : n;
    int mo = sum + 1 - ja;
    printf("%d/%d\n", ja, mo);
}

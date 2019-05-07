#include <stdio.h>
#include <algorithm>

using namespace std;

int main(void)
{
    int n;
    scanf("%d", &n);
 

    if(n == 1) printf("1\n");
    for(int i = 2; i*i <= n; i++) {
        if(n % i == 0){
            n /= i;
            printf("%d\n",i);
            i--;
        }
    }
    if(n > 1) 
        printf("%d\n",n);
}
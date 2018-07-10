#include <array>
#include <stdio.h>

using namespace std;

array<bool,1000001> sieve;

void get_prime(int n) {
    sieve.fill(true);
    sieve[1] = false;
    for(int i = 2; i*i <= n; i++) {
        if(sieve[i] == true) {
            for(int j=i*i; j <= n; j+=i){
                sieve[j] = false;
            } 
        }
    }
}

int main(void)
{
    int m,n;
    scanf("%d %d",&m ,&n);
    get_prime(n);

    for(int i = m; i <= n; i++) {
        if(sieve[i])
            printf("%d\n",i);
    }
}
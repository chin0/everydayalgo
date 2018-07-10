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
    int n = 0;
    get_prime(123456*2);

    while(1) {
        int cnt = 0;
        scanf("%d", &n);
        if(n == 0)
            break;
        for(int i = n+1; i <= 2*n; i++) {
            if(sieve[i])
                cnt++;
        }
        printf("%d\n",cnt);
    }
}
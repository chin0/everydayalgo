#include <array>
#include <stdio.h>

using namespace std;

array<bool,1000001> sieve;

inline int abs(int i) {
    return (i < 0) ? -i : i;
}


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

void get_goldbach_partition(int n)
{
    int p = 0;
    for(int i = n-1; i >= 0; --i) {
        if(sieve[i] && sieve[n-i]) {
            if(abs(p-(n-p)) > abs(i-(n-i)) || p == 0) {
                p = i;
            }
        }
    }
    p = (n-p < p) ? n-p : p;
    printf("%d %d\n",p,n-p); 
}

int main(void)
{
    int n,m;
    get_prime(10000);
    scanf("%d",&n);
    for(int i = 0; i < n; i++) {
        scanf("%d",&m);
        get_goldbach_partition(m);
    }
}
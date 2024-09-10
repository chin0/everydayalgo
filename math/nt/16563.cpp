#include <cstdio>
#include <array>

typedef unsigned long long ll;

using namespace std;
ll sieve[5000001];

int main(void)
{
  int n;
  memset(sieve,0, sizeof(sieve));
  scanf("%d", &n);

  for(ll i = 2; i <= 5000000; i++) {
    if(sieve[i] == 0) {
      sieve[i] = i;
      for(ll j = i*i; j <= 5000000; j+=i) {
        if(sieve[j] == 0) {
          sieve[j] = i;
        }
      }
    }
  }

  for(int i = 1; i <= n; i++) {
    ll k;
    scanf("%lld", &k);
    while(k != 1) {
      printf("%lld ", sieve[k]);
      k /= sieve[k];
    }
    printf("\n");
  }
}

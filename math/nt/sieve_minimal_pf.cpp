#include <cstdio>
#include <array>

using namespace std;

int main(void)
{
  int n = 1000;
  array<int, 1001> sieve;
  sieve.fill(0);

  for(int i = 2; i <= n; i++) {
    if(sieve[i] == 0) {
      
      sieve[i] = i;
      for(int j = i*i; j <= n; j+=i) {
        if(sieve[j] == 0) {
          sieve[j] = i;
        }
      }
    }
  }

  for(int i = 1; i <= 25; i++) {
    printf("(%d %d)\n", i, sieve[i]);
  }
}

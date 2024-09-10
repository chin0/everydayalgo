#include <cstdio>
#include <array>

using namespace std;

int main(void)
{
  int n = 1000;
  array<int, 1000> sieve;
  sieve.fill(0);

  for(int i = 2; i  <= n; i++) {
    if(sieve[i] == 0) {
      sieve[i] = 1;
      for(int j = i*2; j <= n; j+=i) {
        sieve[j] += 1;
      }
    }
  }

  for(int i = 1; i <= 100; i++) {
    printf("(%d %d)\n", i, sieve[i]);
  }
}

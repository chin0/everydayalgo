#include <cstdio>
#include <algorithm>
#include <array>

using namespace std;

int main(void) {
  int n,k;
  array<bool,1000001> sieve;
  sieve.fill(true);

  scanf("%d %d", &n, &k);

  int counter = 0;
  sieve[1] = false;

  for(int i = 2; i <= n; i++) {
    if(sieve[i] == true) {
      counter++;
      if(counter == k) {
        printf("%d\n", i);
        return 0;
      }
      for(int j = i*i; j <= n; j+=i) {
        if(sieve[j] == false)
          continue;
        sieve[j] = false;
        counter++;
        if(counter == k) {
          printf("%d\n", j);
          return 0;
        }
      }
    }
  }
}

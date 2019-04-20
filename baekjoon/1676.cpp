#include <cstdio>

int solve(int n) {
  int count5 = 0;
  int m = 1;
  for(int i = 0; i < 12; i++) {
    m *= 5;
    count5 += n / m;
  }
  return count5;
}

int main()
{
  int n = 0;
  int temp = 0;
  scanf("%d",&n);
  printf("%d\n", solve(n));
}

#include <cstdio>
#include <algorithm>

using namespace std;

int main(void)
{
  int n;

  int d1=0x7fffffff, d2=0,d;
  scanf("%d", &n);

  for(int i = 0; i < n; i++) {
    scanf("%d", &d);
    d1 = min(d1, d);
    d2 = max(d2, d);
  }
  if(n == 1) {
    printf("%d\n", d * d);
  } else {
    printf("%d\n", d1 * d2);
  }
}

#include <cstdio>
#include <algorithm>

using namespace std;
using llu = unsigned long long int;

//이항계수의 계산 방식을 생각하면 자명함.
int solve(llu n) {
  llu count5 = 0;
  llu m = 1;
  for(int i = 0; i < 14; i++) {
    m *= 5;
    count5 += n / m;
  }
  return count5;
}
int solve2(llu n) {
    llu count2 = 0;
    llu m = 1;
    for(int i= 0; i < 32; i++) {
        m *= 2;
        count2 += n/m;
    }
    return count2;
}


int main(void) {
    int n,m;
    scanf("%d %d", &n, &m);
    int result = solve(n) - (solve(m) + solve(n-m));
    int result2 = solve2(n) - (solve2(m) + solve2(n-m));
    printf("%d\n",min(result,result2));
}
#include <cstdio>

//binary exponential algorithm.
long long pow(long long n, long long p, long long m)
{
  long long ret = 1;
  while(p > 0) {
    if(p & 1)
      ret = (ret * n) % m;
    n = (n * n) % m;
    p >>= 1;
  }
  return ret;
}

int main(void) 
{
  long long a,b,c;
  scanf("%lld %lld %lld", &a, &b, &c);
  printf("%lld\n",pow(a,b,c));
}

#include <cstdio>

int iroot(int n) {
  if(n == 0 || n == 1) {
    return n;
  }

  switch(n & 0xF) {
    case 0:
    case 1:
    case 4:
    case 9:
      break;
    default:
      return -1;
  }

  int s = 0,e = n;
  while(s <= e) {
    int mid = (s+e) / 2;
    if(mid * mid  == n) //if perfect square
      return mid;
    if(mid * mid < n) {
      s = mid + 1;
    } else {
      e = mid-1;
    }
  }
  return -1;
}

int main(void)
{
  int n,m;
  scanf("%d %d",&n,&m);

  int sum = 0;
  int min = 0;
  bool notfound = false;
  for(int i = n; i <= m; i++) {
    if(iroot(i) != -1) {
      if(notfound == false) {
        notfound = true;
        min = i;
      }
      sum += i;
    }
  }
  if(!notfound)
    printf("-1\n");
  else
    printf("%d\n%d", sum, min);
}

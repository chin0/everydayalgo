#include <cstdio>
#include <cmath>

int main() {
   unsigned long long int n;
   unsigned long long int arr[150] = { 1,1,1, };
   scanf("%llu", &n);

   for (int i = 3; i < n; i++) {
      arr[i] = arr[i - 1] + arr[i - 3];
   }
   printf("%llu", arr[n - 1]);
}

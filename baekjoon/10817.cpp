#include <cstdio>
#include <algorithm>

using namespace std;
//xor method
int main(void)
{
    int a, b, c;
    scanf("%d %d %d", &a, &b, &c); 

    printf("%d\n",a ^ b ^ c ^ max(max(a,b),c) ^ min(min(a,b),c));
}

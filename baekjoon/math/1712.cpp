#include <string>
#include <cstdio>

using namespace std;

int main(void)
{
    int a, b, c;
    scanf("%d %d %d",&a,&b,&c);
    if(c <= b) {
        printf("-1\n");
        return 0;
    }
    printf("%d\n", a/(c-b) + 1);
}


#include <cstdio>

using namespace std;

bool eureka(int n, int depth) {
    if(depth > 3) return false;
    if(n == 0 && depth == 3) return true;
    for(int k = 1; k * (k+1) / 2 <= n; k++) {
        if(eureka(n - (k*(k+1) / 2), depth + 1)) return true;
    }
    return false;
}

int main(void)
{
    int t;
    scanf("%d", &t);

    for(int i = 0; i < t; i++) {
        int n;
        scanf("%d", &n);
        printf("%d\n", eureka(n, 0));
    }
}
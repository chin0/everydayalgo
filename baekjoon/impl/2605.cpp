#include <cstdio>
#include <vector>

using namespace std;

int main()
{
    int n;
    scanf("%d", &n);
    vector<int> a;

    for(int i = 0; i < n; i++) {
        int p;
        scanf("%d", &p);
        a.insert(a.begin()+ i-p, i+1);
    }

    for(int i = 0; i < n; i++) {
        printf("%d ", a[i]);
    }
    printf("\n");
}

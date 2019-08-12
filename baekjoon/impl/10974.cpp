#include <cstdio>
#include <algorithm>
#include <vector>

using namespace std;

int main()
{
    int n;
    scanf("%d", &n);
    vector<int> a(n);

    for(int i = 0; i < n; i++) {
        a[i] = i+1;
    }
    do {
        for(int i = 0; i < n; i++) {
            printf("%d ", a[i]);
        }
        printf("\n");
    } while(next_permutation(a.begin(), a.end()));
}

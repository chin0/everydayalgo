#include <stdio.h>
#include <algorithm>
#include <vector>

using namespace std;

bool visited[1001];

void visit(int v,const int permutation[])
{
    int current = v;
    while(permutation[current] != v) {
        visited[current] = true;
        current = permutation[current];
    }
    visited[current] = true;
}

int main(void)
{
    int t;
    scanf("%d", &t);

    for(int i = 0; i < t; i++ ) {
        int n, ans = 0;
        scanf("%d", &n);
        fill(visited, visited + n + 1, false);
        int permutation[n];
        for(int j = 1; j <= n; j++) {
            int a;
            scanf("%d", &a);
            if(a == j) ans++, visited[j] = true;
            permutation[j] = a;
        }
        for(int j = 1; j <= n; j++) {
            if(visited[j]) continue;
            visit(j,permutation);
            ans++;
        }
        printf("%d\n",ans);
    }
}
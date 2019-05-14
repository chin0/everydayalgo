#include <stdio.h>
#include <set>

using namespace std;

//유니온- 파인드로 풀었음.
int list[1001];

// path compression
int find(int x) {
    if(x == list[x]) return x;
    int root = find(list[x]);
    list[x] = root;
    return root;
}

void _union(int x, int y) {
    list[find(x)] = find(y);
}

bool connected(int x, int y) {
    return find(x) == find(y);
}
int main(void)
{
    int n,m;
    scanf("%d %d", &n,&m);
    set<int> s;
    for(int i = 1; i <= n; i++) {
        list[i] = i;
    }

    for(int i= 0; i < m; i++) {
        int a,b;
        scanf("%d %d", &a, &b);
        _union(a,b);
    }
    for(int i = 1; i <= n; i++) {
        s.insert(find(i));
    }
    printf("%d\n", s.size());
}
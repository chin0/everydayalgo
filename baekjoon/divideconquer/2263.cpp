#include <cstdio>
int inorder[100000];
int postorder[100000];
int position[100001];

void solve(int is, int ie, int ps, int pe)
{
    if(is > ie || ps> pe) return;
    int root = postorder[pe];
    printf("%d ", root);
    int p = position[root];

    int left = p-is;
    solve(is, p-1, ps, ps+left -1);
    solve(p+1,ie,ps+left,pe-1);
}
int main() {
    int n;
    scanf("%d", &n);
    for(int i = 0; i < n; i++) scanf("%d", &inorder[i]);
    for(int i = 0; i < n; i++) scanf("%d", &postorder[i]);
    for(int i = 0; i < n; i++) {
        position[inorder[i]] = i;
    }
    solve(0,n-1,0,n-1);
    return 0;
}

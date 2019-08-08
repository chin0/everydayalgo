#include <iostream>
int a[1000000];
int b[1000000];
int c[1000000];

int main() {
    int n,m;
    scanf("%d %d", &n, &m);
    for(int i = 0; i < n; i++) scanf("%d", &a[i]);
    for(int i = 0; i < m; i++) scanf("%d", &b[i]);
    int i = 0;
    int j = 0;
    int k = 0;
    while(i < n && j < m) {
        if(a[i] <= b[j]) {
            c[k++] = a[i++];
        } else {
            c[k++] = b[j++];
        }
    }
    while(i < n) {
        c[k++] = a[i++];
    }
    while(j < m) {
        c[k++] = b[j++];
    }
    for(int i = 0; i < n+m; i++) {
        printf("%d ", c[i]);
    }
    printf("\n");
    return 0;
}

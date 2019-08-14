#include <iostream>
#include <cstring>

int d[2000][2000];
int a[2000];

int go(int i, int j)
{
    if(i == j)
        return 1;
    else if(i+1 == j) {
        if(a[i] == a[j]) {
            return 1;
        } else {
            return 0;
        }
    }
    if(d[i][j] != -1)
        return d[i][j];
    if(a[i] != a[j])
        return d[i][j] = 0;
    else
        return d[i][j] = go(i+1,j-1);
}

int main()
{
    int n;
    scanf("%d", &n);
    for(int i = 0; i < n; i++)
        scanf("%d", &a[i]);
    memset(d,-1,sizeof(d));
    int m;
    scanf("%d", &m);
    while(m--) {
        int s,e;
        scanf("%d %d", &s, &e);
        printf("%d\n", go(s-1,e-1));
    }
    return 0;
}

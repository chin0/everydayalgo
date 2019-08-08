#include <cstdio>
#include <cstdlib>

#define BLANK 0
#define STAR 1
void go(char **a, int x, int y, int n, int color)
{
    int i,j;
    int newColor;
    if(color == BLANK) {
        for(i=x; i < x+n; i++) {
            for(j = y; j<y+n; j++) {
                a[i][j] = ' ';
            }
        }
    } else {
        if(n == 1) {
            a[x][y] = '*';
        } else {
            newColor = STAR;
            int m = n/3;
            for(i = 0; i < 3; i++) {
                for(j = 0; j < 3; j++) {
                    if(i==1 && j == 1) {
                        newColor = BLANK;
                    } else {
                        newColor = STAR;
                    }
                    go(a,x+m*i, y+m*j,m,newColor);
                }
            }
        }
    }
}
int main()
{
    int n ;
    int i,j;
    char **a;
    scanf("%d", &n);
    a = (char **)malloc(sizeof(char *) * n);
    for(i = 0; i < n; i++) {
        a[i] = (char *)malloc(sizeof(char)*(n+1));//널문자때문에 +1
    }
    for(i = 0; i < n; i++) {
        for(j = 0; j < n+1; j++) {
            a[i][j] = 0;
        }
    }
    go(a,0,0,n,STAR);
    for( i = 0; i < n; i++) {
        printf("%s\n", a[i]);
    }
    return 0;
}

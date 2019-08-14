#include <cstdio>
int a[101];
int d[101][101];
bool c[101][101];

int min = -32768 * 101;

int go(int n, int m)
{
    if(m == 0) { //m만큼 구간을 전부 나눈경우
        return 0;
    }
    if(n <= 0) { //m만큼 구간을 나누지 못했을때. 즉, m > 0
        return min; //여기서 min대신 0을 넣으면 m 이하의 구간을 구하는 코드가 되므로 안댐. 
    }
    if(c[n][m]) return d[n][m];
    c[n][m] = true;
    int &ans = d[n][m];
    ans = go(n-1,m);
    int sum = 0;
    for(int k = n; k>=1; k--) {
        sum += a[k];
        int temp = go(k-2,m-1) + sum;
        if(ans < temp) ans = temp;
    }
    return ans;
}

int main()
{
    int n,m;
    scanf("%d %d", &n, &m);
    for(int i = 1; i <= n; i++)
        scanf("%d", &a[i]);
    printf("%d\n",go(n,m));
}

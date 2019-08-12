#include <iostream>

using namespace std;
int a[20];
int n,m;
int ans = 0;
void go(int i, int sum)
{
    if(i == n) {
        if(sum == m) {
            ans += 1;
        }
        return;
    }
    //포함하는경우
    go(i+1, sum+a[i]);
    //포함하지 않는경우
    go(i+1, sum);
}

int main()
{
    cin >> n >> m;
    for(int i = 0; i < n; i++)
        cin >> a[i];
    go(0,0);
    if(m == 0) ans -= 1;
    cout << ans << endl;
}

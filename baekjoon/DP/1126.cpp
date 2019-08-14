#include <iostream>
#include <cstring>
#include <algorithm>

using namespace std;
const int inf = 10000000;
int a[50];
int d[50][250001];
int n;
int go(int k, int diff) {
    if(diff > 250000)
        return -inf;
    if(k == n) {
        if(diff == 0)
            return 0;
        else
            return -inf;
    }

    int &ans = d[k][diff];
    if(ans != -1)
        return ans;
    ans = go(k+1,diff);
    ans = max(ans,go(k+1,diff+a[k]));
//차를 저장하는것이기 때문에 더해주거나 빼주는 작업이 필수!
    if(a[k] > diff)
        ans = max(ans,diff + go(k+1, a[k]-diff));
    else
        ans = max(ans, a[k] + go(k+1,diff-a[k])); 
    return ans;
}
int main()
{
    cin >> n;
    for(int i = 0; i < n; i++)
        cin >> a[i];
    memset(d,-1,sizeof(d));
    int ans = go(0,0);
    if (ans == 0) {
        cout << -1 << '\n';
    } else {
        cout << ans << '\n';
    }
    return 0;
}

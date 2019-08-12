#include <iostream>

using namespace std;

int a[20];
int main()
{
    int n,s;
    cin >> n >> s;
    for(int i = 0; i < n; i++) {
        cin >> a[i];
    }
    int ans = 0;
    for(int i = 1; i < (1<<n); i++) {
        int sum = 0;
        for(int k = 0; k < n; k++) {
            if(i&(1<<k)) {
                sum += a[k];
            }
        }
        if(sum == s)
            ans += 1;
    }
    cout << ans <<  endl;
    return 0;
}

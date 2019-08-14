#include <iostream>
#include <vector>
using namespace std;
long long d[100][21];
int main()
{
    int n;
    cin >> n;
    n -= 1;
    vector<int> a(n);
    for(int i = 0; i < n; i++) {
        cin >> a[i];
    }
    int goal;
    cin >> goal;
    d[0][a[0]] = 1;
    for(int i = 1; i < n; i++) {
        for(int j = 0; j <= 20; j++) {
            if(j-a[i] >= 0)
                d[i][j] += d[i-1][j-a[i]];
            if(j+a[i] <= 20)
                d[i][j] += d[i-1][j+a[i]];
        }
    }
    cout << d[n-1][goal] << '\n';
}

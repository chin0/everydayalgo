#include <cstdio>
#include <iostream>

using namespace std;

int a[100][100];

int main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int n,m;
    cin >> n >> m;
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            cin >> a[i][j];
        }
    }
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            int temp;
            cin >> temp;
            a[i][j] += temp;
        }
    }
    for(int i = 0; i < n; i++) {
        for(int j =0; j < m; j++)
            cout << a[i][j] << ' ';
        cout << '\n';
    }
}

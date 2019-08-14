#include <iostream>

int a[100][100];
int b[100][100];
int c[100][100];

using namespace std;

int main(void)
{
    cin.tie(NULL);
    ios::sync_with_stdio(false);

    int n,m,k;
    cin >> n >> m;
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            cin >> a[i][j];
        }
    }
    cin >> m >> k;
    for(int i = 0; i < m; i++) {
        for(int j = 0; j < k; j++) {
            cin >> b[i][j];
        }
    }

    for(int i = 0; i < n; i++) {
        for(int j = 0; j < k;j++) {
            c[i][j] = 0;
            for(int l = 0; l < m; l++) {
                c[i][j] += a[i][l] * b[l][j];
            }
        }
    }
    for(int i =0; i < n; i++) {
        for(int j = 0; j < k; j++) {
            cout << c[i][j] << ' ';
        }
        cout << '\n';
    }
}

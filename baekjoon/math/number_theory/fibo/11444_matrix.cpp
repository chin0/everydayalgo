#include <iostream>
#include <vector>

using namespace std;

typedef vector<vector<long long>> matrix;
long long mod = 1000000007;

matrix operator*(matrix& a, matrix& b)
{
    matrix ans(2,vector<long long>(2));
    for(int i = 0; i < 2; i++) {
        for(int j = 0; j < 2; j++) {
            for(int k = 0; k < 2; k++) {
                ans[i][j] += a[i][k] * b[k][j];
            }
            ans[i][j] %= mod;
        }
    }
    return ans;
}

int main(void)
{
    long long n;
    cin >> n;

    matrix fibo(2,vector<long long>(2));
    matrix ans(2,vector<long long>(2));
    fibo = {{1,1},{1,0}};
    ans = {{1,0},{0,1}};
    while(n > 0) {
        if((n&1) == 1)
            ans = ans * fibo;
        fibo = fibo * fibo;
        n >>= 1;
    }
    cout << ans[0][1] << endl;
}

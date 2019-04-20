#include <iostream>
#include <vector>

using namespace std;

long long c[1001];
int main(void)
{
    std::ios::sync_with_stdio(false);
    long long result = 0;
    long long n,m,sum=0,temp;

    cin >> n >> m;
    c[0]=1; // 나머지가 0인 경우는 서로 다른 두개뿐만 아니라 자기자신을 뽑아도 되니 nC1 + nC2 = (n+1)C2  그러므로 초기값으로 1.
    for(int i = 0; i < n; i++) {
        cin >> temp;
        sum += temp;
        sum %= m;
        c[sum]++;
    }

    for(int i = 0; i < m; i++) {
        if(c[i])
            result += c[i] * (c[i]-1) / 2;
    }
    cout << result << endl;
}
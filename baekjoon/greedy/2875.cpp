#include <iostream>

using namespace std;

int main(void)
{
    int n,m,k;
    int result = 0;

    cin >> n >> m >> k;

    //요구하는 조건을 만족할때까지 계속 반복. 
    while(n + m >= k + 3 && n >= 2 && m >= 1 ) {
        result += 1;
        n -= 2;
        m -= 1;
    }
    cout << result << endl;

}

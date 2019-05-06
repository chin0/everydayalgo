#include <string>
#include <iostream>
#include <algorithm>
using namespace std;

int main(void)
{
    int n,m,r,temp;
    string s;
    cin >> s;

    reverse(s.begin(), s.end());

    n = s.size() / 3;
    m = s.size() % 3;
    r = 1;
    temp = 0;
    for(int i = 0; i < m; i++) {
        temp += r * (s[n* 3 + i] - '0');
        r *= 2;
    }
    if(temp || n == 0)
        cout << temp;
     for(int i = n-1; i >= 0; i--) {
        r = 1;
        temp = 0;
        for(int j = 0; j < 3; j++) {
            temp += r * (s[i* 3 + j] - '0');
            r *= 2;
        }
        cout << temp;
    }
    cout << endl;
}
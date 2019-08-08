// 배수판정법을 이용하여 풀면 댐.
#include <string>
#include <iostream>
#include <algorihtm>

using namespace std;

int main()
{
    string s;
    cin >> s;
    int sum = 0;

    for(char c : s) {
        sum += c - '0';
    }
    sort(s.begin(), s.end());
    if(s[0] == '0' && sum%3 == 0) {
        reverse(s.begin(), s.end());
        cout << s << endl;
    } else {
        cout << "-1" << endl;
    }
    return 0;
}

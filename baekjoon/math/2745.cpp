#include <locale>
#include <iostream>
#include <string>


using namespace std;

int main(void)
{
    unsigned long long int result = 0;
    int b;
    string s;
    ios::sync_with_stdio(false);
    cin >> s;
    cin >> b;
    unsigned long long int r = 1;
    
    for(int i = s.size() - 1; i >= 0; i--) {
        if('0' <= s[i] && s[i] <= '9') {
            result += r * (s[i] - '0');
        } else if (isupper(s[i])) {
            result += r * (s[i] - 'A' + 10);
        }
        r *= b;
    }
    cout << result << endl;
}
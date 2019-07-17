#include <string>
#include <iostream>

using namespace std;

int main(void)
{
    ios::sync_with_stdio(false);
    string s;
    getline(cin,s);
    while(s != "END") {
        reverse(s.begin(), s.end());
        cout << s << endl;
        getline(cin,s);
    }
}

#include <iostream>
#include <string>
#include <cctype>

using namespace std;

int main(void)
{
    ios::sync_with_stdio(false);
    string s;

    cin >> s;
    for(auto i : s){
        if(isupper(i)) {
            cout << i;
        }
    }
    cout << endl;
}

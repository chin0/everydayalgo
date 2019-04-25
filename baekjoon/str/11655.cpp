#include <iostream>
#include <string>
#include <locale>

using namespace std;

int main(void)
{
    char o;
    string s;
    getline(cin,s);

    for(auto i : s) {
        if(islower(i)) {
            o = ((i - 'a') + 13) % 26 + 'a';
            cout << o;
        } else if(isupper(i)) {
            o = ((i - 'A') + 13) % 26 + 'A';
            cout << o;
        } else if(i == ' ') {
            cout << ' ';
        } else if(i >= '0' && i <= '9'){
            cout << i;
        }
    }
    cout << endl;
}
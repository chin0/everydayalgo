#include <iostream>
#include <string>

using namespace std;

int main(void)
{
    int count[26] = {0,};
    string s;

    ios::sync_with_stdio(false);

    cin >> s;

    for(auto i : s) {
        count[i - 'a']++;
    }

    for(auto i : count) {
        cout << i << " ";
    }
    cout << endl;
}
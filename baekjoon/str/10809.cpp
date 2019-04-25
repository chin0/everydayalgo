#include <iostream>
#include <algorithm>
#include <string>

using namespace std;

int main(void)
{
    int count[26];
    string s;

    ios::sync_with_stdio(false);

    fill(count,count+26,-1);

    cin >> s;

    for(int i = 0; i < s.length(); i++) {
        if(count[s[i] - 'a'] == -1) {
            count[s[i] - 'a'] = i;
        }
    }

    for(auto i : count) {
        cout << i << ' ';
    }
    cout << endl;
}
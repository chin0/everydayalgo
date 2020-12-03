#include <iostream>
#include <cstdio>

using namespace std;

string solve(string s) {
    if(s[0] != 'x') {
        return s.substr(0,1);
    }
    
    s = s.substr(1);
    //cout << s << endl;
    string split[4];
    for(int i = 0; i < 4; i++) {
        split[i] = solve(s);
        s = s.substr(split[i].length());
    }
    return "x"+split[2] + split[3] + split[0] + split[1];
}

int main(void) {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL); 

    int c;
    cin >> c;
    for(int i = 0; i < c; i++) {
        string s;
        cin >> s;
        cout << solve(s) << endl;
    }
}
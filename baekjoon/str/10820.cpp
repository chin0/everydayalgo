#include <iostream>
#include <algorithm>
#include <string>
#include <locale>

using namespace std;

int main(void)
{
    int n;
    int count[4];
    string s;

    ios::sync_with_stdio(false);



    while(1) { 
        getline(cin,s);
        if(s.empty()) {
            break;
        }
        fill(count,count+4,0);

        for(int i = 0; i < s.length(); i++) {
            if(islower(s[i])) {
                count[0]++;
            } else if(isupper(s[i])) {
                count[1]++;
            } else if(s[i] <= '9' && s[i] >= '0') {
                count[2]++;
            } else if(s[i] == ' ') {
                count[3]++;
            }
        }

        for(auto i : count) {
            cout << i << ' ';
        }
        cout << endl;
    }
}
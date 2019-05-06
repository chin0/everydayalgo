#include <iostream>
#include <string>
#include <algorithm>
#include <stack>
using namespace std;

int main(void)
{
    string s;
    ios::sync_with_stdio(false);
    cin >> s;

    for(int i = 0; i < s.size(); i++) {
        int temp = s[i] - '0';
        stack<int> st;
        while(temp) {
            st.push(temp % 2);
            temp /=2;
        }
        if(i != 0)
            for(int j = 0; j < 3 - st.size(); j++)
                cout << "0";
        if(i == 0 && st.size() == 0 && s.size() == 1)
            cout << "0";
        while(!st.empty()) {
            cout << st.top();
            st.pop();
        }
    }
    cout << endl;
}
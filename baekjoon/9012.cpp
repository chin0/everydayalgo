#include <iostream>
#include <stack>
#include <string>

using namespace std;

int main(void) {
    std::ios::sync_with_stdio(false);
    int n;
    string s;
    stack<char> st;
    cin >> n;
    for(int i = 0; i < n; i++) {
        cin >> s;
        bool is_valid = true;
        for(auto i : s) {
            if(i == '(')
                st.push('(');
            else if(i == ')') {
                if(st.empty()) {
                    is_valid = false;
                    break;
                } else {
                    st.pop();
                }
            }
        }
        if(!st.empty()) {
            is_valid = false;
            while(!st.empty())
                st.pop();
        }
        cout << (is_valid ? "YES" : "NO") << endl;
    }
}
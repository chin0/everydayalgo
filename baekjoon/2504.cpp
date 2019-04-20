#include <iostream>
#include <stack>
#include <string>

using namespace std;

int main(void) {
    std::ios::sync_with_stdio(false);
    string s;
    bool is_valid = true;
    int temp = 1;
    int result = 0;
    stack<char> st;
    cin >> s;
    for(int i = 0; i < s.length(); i++) {
        if(s[i] == '(') {
            temp *= 2;
            st.push('(');
        } 
        else if(s[i] == '[') {
            temp *= 3;
            st.push('[');
        }
        else if(s[i] == ')') {
            if(st.empty()|| st.top() != '(') { is_valid = false; break; }
            if(s[i-1] == '(') result += temp;
            temp /= 2;
            st.pop();
        } 
        else if(s[i] == ']') {
            if(st.empty() || st.top() != '[') { is_valid = false; break; }
            if(s[i-1] == '[') result += temp;
            temp /= 3;
            st.pop();
        }
    }
    if(is_valid == false || !st.empty()) {
        cout << '0' << endl;
    } else {
        cout << result << endl;
    }
}
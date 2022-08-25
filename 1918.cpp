#include <iostream>
#include <string>
#include <stack>
#include <iomanip>

using namespace std;

int getprecendence(char c) {
    switch (c)
    {
        case '*': return 2;
        case '/': return 2;
        case '+': return 1;
        case '-': return 1;
    }
}
int main(void){
    string infix;
    stack<char> s;

    cin.tie(NULL);
    cout.tie(NULL);
    ios::sync_with_stdio(false);

    cin >> infix;
    for(auto i : infix) {
        if(isalpha(i)) {
            cout << i;
        } else {
            if(s.empty()) {
                s.push(i);
                continue;
            }
            char op = s.top();
            if(i == '('){
                s.push(i);
            } else if(i == ')') {
                while(s.top() != '(') {
                    if(s.top() != '(' && s.top() != ')')
                        cout <<s.top();
                    s.pop();
                }
                s.pop();
            } else if(s.top() == '(' ||getprecendence(i) > getprecendence(op)) {
                s.push(i);
            }else {
                while(!s.empty() && 
                    getprecendence(i) <= getprecendence(s.top()) &&
                    s.top() != '(') {
                    if(s.top() != '(' && s.top() != ')')
                        cout <<s.top();
                    s.pop();
                }
                s.push(i);
            }
        }
    }
    while(!s.empty()) {
        cout <<s.top();
        s.pop();
    }
}
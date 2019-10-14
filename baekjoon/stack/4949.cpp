#include <string>
#include <stack>
#include <iostream>

using namespace std;

int main(void)
{
    cin.tie(NULL);
    ios::sync_with_stdio(false);

    string s;
    while(true) {
        bool is_balenced = true;
        stack<char> p;
        getline(cin,s);
        if(s == ".") break;

        for(auto i : s) {
            if(i == '(') p.push(i);
            else if(i == '[') p.push(i);

            if(i == ')') {
                if(!p.empty() && p.top() == '(') p.pop();
                else {
                    is_balenced = false;
                    break;
                }
            }
            else if(i == ']') {
                if(!p.empty() && p.top() == '[') p.pop();
                else {
                    is_balenced = false;
                    break;
                }
            }
        }
        if(!p.empty()) is_balenced = false;
        if(is_balenced) cout << "yes\n";
        else cout << "no\n";
    }
}

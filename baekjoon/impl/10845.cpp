#include <iostream>
#include <string>
#include <queue>

using namespace std;

int main(void) {
    int n,temp;

    string s;

    queue<int> q;

    ios::sync_with_stdio(false);

    cin >> n;
    for(int i = 0; i < n; i++) {
        cin >> s;
        if(s == "push") {
            cin >> temp;
            q.push(temp);
        } else if(s == "pop") {
            if(q.empty()) {
                cout << "-1" << endl;
            } else {
                cout << q.front() << endl;
                q.pop();
            }
        } else if(s == "front") {
            if(q.empty()) {
                cout << "-1" << endl;
            } else {
                cout << q.front() << endl;
            }
        } else if(s == "back") {
            if(q.empty()) {
                cout << "-1" << endl;
            } else {
                cout << q.back() << endl;
            }
        } else if(s == "empty") {
            cout << (int)q.empty() << endl;
        } else if(s == "size") {
            cout << q.size() << endl;
        }
    }
}
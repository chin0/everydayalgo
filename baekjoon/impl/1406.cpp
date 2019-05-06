#include <iostream>
#include <list>
#include <string>

using namespace std;

int main(void) 
{
    ios::sync_with_stdio(false);
    int n;
    char op;
    string s;
    list<char> editor;

    cin >> s;

    for(auto i : s) {
        editor.emplace_back(i);
    }
    auto cursor = editor.end();

    cin >> n;
    for(int i = 0; i < n; i++) {
        cin >> op;
        if(op == 'L') {
            if(cursor != editor.begin())
                cursor--;
        }
        if(op == 'D') {
            if(cursor != editor.end())
                cursor++;
        }
        if(op == 'B' && !editor.empty()) {
            if(cursor != editor.begin()){
                cursor = editor.erase(--cursor);
            }
        }
        if(op == 'P') {
            char temp;
            cin >> temp;
            cursor = editor.insert(cursor, temp);
            cursor++;
        }
    }

    for(auto i : editor) {
        cout << i;
    }
    cout << endl;
}
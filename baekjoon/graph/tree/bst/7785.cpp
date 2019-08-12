#include <set>
#include <string>
#include <iostream>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n;
    cin >> n;
    set<string> s;
    while(n--) {
        string name, what;
        cin >> name >> what;
        if(what == "enter") {
            s.insert(name);
        } else {
            s.erase(s.find(name));
        }
    }
    //사전순 역순으로 출력해야함
    for(auto it = s.rbegin(); it!=s.rend(); it++) {
        cout << *it << '\n';
    }
    return 0;
}

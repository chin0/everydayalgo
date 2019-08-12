#include <iostream>
#include <string>
#include <map>
#include <vector>

using namespace std;

int main()
{
    map<string,int> d;
    int n,m;
    cin >> n >> m;

    while(n--) {
        string name;
        cin >> name;
        d[name] |= 1;
    }
    while(m--) {
        string name;
        cin >> name;
        d[name] |= 2;
    }

    vector<string> ans;
    for(auto &p : d) {
        if(p.second == 3) {
            ans.push_back(p.first);
        }
    }
    cout << ans.size() << '\n';
    for(auto &name : ans) {
        cout << name << '\n';
    }
}


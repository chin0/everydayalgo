#include <set>
#include <string>
#include <vector>
#include <iostream>
#include <algorithm>
#include <set>

using namespace std;

int main()
{
    set<string> s;
    int n,m;
    cin >> n >> m;
    while(n--) {
        string name;
        cin >> name;
        s.insert(name);
    }

    vector<string> ans;
    while(m--) {
        string name;
        cin >> name;
        if(s.count(name)) {
            ans.push_back(name);
        }
    }
    sort(ans.begin(), ans.end());
    cout << ans.size() << '\n';
    for(auto &name : ans) {
        cout << name << '\n';
    }
    return 0;
}

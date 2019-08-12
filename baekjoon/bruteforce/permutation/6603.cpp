#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main(void)
{
    while(true) {
        int n;
        cin >> n;
        if(n == 0)
            break;

        vector<int> a(n);
        for(int i = 0; i < n; i++)
            cin >> a[i];

        vector<int> d;
        for(int i = 0; i < n-6; i++)
            d.push_back(0);
        for(int i = 0; i < 6; i++)
            d.push_back(1);

        vector<vector<int>> ans;
        do {
            vector<int> current;
            for(int i = 0; i < n; i++) {
                if(d[i] == 1)
                    current.push_back(a[i]);
            }
            ans.push_back(current);
        } while(next_permutation(d.begin(), d.end()));
        sort(ans.begin(), ans.end());
        for(auto &v : ans) {
            for(int i = 0 ; i < v.size(); i++)
                cout << v[i] << ' ';
            cout << endl;
        }
        cout << endl;
    }
}

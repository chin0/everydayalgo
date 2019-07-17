#include <iostream>
#include <string>

using namespace std;

int main(void)
{
    ios::sync_with_stdio(false);
   
    int t,r;
    string s;
    cin >> t;
    for(int i = 0; i < t; i++) {
        cin >> r >> s;
        for(auto k : s) {
            for(int j = 0; j < r; j++) {
                cout << k;
            }
        }
        cout << endl;
    }
    
}

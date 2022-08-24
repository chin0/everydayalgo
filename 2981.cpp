#include <vector>
#include <iomanip>
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main(void) 
{
    int n;
    vector<int> numlist;
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> n;
    for(int i = 0; i < n; i++) {
        int num;
        cin >> num;
        numlist.push_back(num);
    }

    sort(numlist.begin(), numlist.end());

    int diff = numlist[numlist.size() - 1] - numlist[0];
    vector<int> factor;
    factor.push_back(diff);

    for(int i = 2; i*i <= diff; i++) {
        if(diff % i == 0) {
            factor.push_back(i);
            if(diff / i != i)
                factor.push_back(diff/i);
        }
    }
    sort(factor.begin(), factor.end());
    for(auto i : factor) {
        bool isans = true;
        int mod = numlist[0] % i;
        for(auto j : numlist) {
            if(j % i != mod) {
                isans = false;
                break;
            }
        }
        if(isans) {
            cout << i << ' ';
        }
    }
    cout << '\n';
    return 0;
}
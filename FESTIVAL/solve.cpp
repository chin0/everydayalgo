#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

double solve() {
    int n,l,temp;
    cin >> n >> l;

    vector<int> costlist;
    
    for(int i = 0; i < n; i++) {
        cin >> temp;
        costlist.push_back(temp);
    }
    double result = 200000;
    for(int dis = l; dis < n+1; dis++) {
        for(int j = 0; j < (n-dis+1); j++) {
            double sum = 0;
            for(int k = j; k < (j+dis); k++) {
                sum += costlist[k];
            }
            result = min(result, sum/dis);
        }
    }
    return result;
}

int main() {
    int c;
    cin >> c;
    cout.setf(ios::showpoint);
    cout.precision(10);
    for(int i = 0; i < c; i++) {
        double result = solve();
        cout << result << endl;
    }
}

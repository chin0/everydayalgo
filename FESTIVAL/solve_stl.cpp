#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>
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
    for(int i = l; i < n+1; i++) {
        for(int j = 0; j < (n-i+1); j++) {
            double sum = std::accumulate(costlist.begin() + j,
                    costlist.begin() + (j+i),0);
            result = min(result, sum/i);
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

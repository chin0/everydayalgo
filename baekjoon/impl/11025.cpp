#include <iostream>

using namespace std;

int main(void)
{
    int n,k;
    ios::sync_with_stdio(false);
    cin >> n >> k;
    
    int current = 1;

    for(int i = 2; i <= n; i++) {
        current = ((current + k-1) % i) + 1;
    }
    cout << current << endl;
}
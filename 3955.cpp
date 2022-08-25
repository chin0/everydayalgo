#include <iomanip>
#include <tuple>
#include <iostream>
#include <stdint.h>

using namespace std;

tuple<int64_t, int64_t,int64_t> xgcd(int64_t a, int64_t b) {
    if(b == 0) return make_tuple(a, 1,0);
    int64_t g,x,y;
    tie(g,x,y) = xgcd(b, a%b);
    return make_tuple(g,y,x-(a/b)*y);
}

int main(void) {
    int k,c,t;
    cin.tie(NULL);
    cout.tie(NULL);
    ios::sync_with_stdio(false);

    cin >> t;
    for(int i = 0; i < t; i++) {
        cin >> k >> c;

        int64_t g,x,y;
        tie(g,x,y) = xgcd(c,k);
        if(g != 1) {
            cout << "IMPOSSIBLE\n";
            continue;
        }
        while(y >= 0) {
            y -= c;
            x += k;
        }
        if(x >= 1000000000){
            cout << "IMPOSSIBLE\n";
            continue;
        }
        cout << x << '\n';
    }
}

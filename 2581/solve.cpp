#include <iostream>

using namespace std;

bool prime_test(int n) {
    if(n <= 1)
        return false;

    for(int i = 2; i*i <= n; i++) {
        if(n % i == 0)
            return false;
    }
    return true;
}
    
int main(void) {
    int m,p,n,cnt=0,min=0;

    cin >> m >> n;

    for(int i = m; i <= n; i++){
        if(prime_test(i)){
            if(!min) {
                min = i;
            }
            cnt += i; 
        }
    }
    if(min == 0) {
        cout << -1 << endl;
    } else {
        cout << cnt << endl << min << endl;
    }
}


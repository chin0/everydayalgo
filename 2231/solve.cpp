#include <iostream>

using namespace std;

inline int ndigit(int n) {
    int i = 1;
    while(n /= 10) i++;
    return i;
}

inline int digitsum(int n) {
    int i = n % 10;
    while(n /= 10) i += n % 10;
    return i;
}

int get_generator(int n) {
    for(int i = n-(9*ndigit(n)); i < n; i++) {
        int current = i + digitsum(i);
        if(current == n) return i;
    }
    return 0;
}
int main() {
    int n;

    ios_base::sync_with_stdio(false);
    cin >> n;
    cout << get_generator(n) << endl;
}
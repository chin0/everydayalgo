//suffix array
//N^2logN algorithm
#include <algorithm>
#include <iostream>
#include <string>

using namespace std;

struct suffix {
    int index;
    string s;
};

bool cmp(suffix s1, suffix s2) {
    return s1.s < s2.s;
}
int main(void)
{
    suffix array[1000];
    string s;
    ios::sync_with_stdio(false);
    cin >> s;

    for(int i = 0; i < s.length(); i++) {
        array[i].index = i;
        array[i].s = s.substr(i);
    }
    sort(array, array+s.length(),cmp);
    for(int i = 0; i < s.length(); i++) {
        cout << array[i].s << endl;
    }
}
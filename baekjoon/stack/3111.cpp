#include <string>
#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

int main(void)
{
    ios::sync_with_stdio(false);

    string L;
    string R;
    string s;
    string t;
    bool isLeft = true;

    cin >> t;
    cin >> s;
    while(!s.empty()) {
        if(isLeft) {
            char temp = *s.begin();
            L.push_back(temp);
            s.erase(s.begin());
            int lsize = L.size();
            int tsize = t.size();
            bool isFind = false;
            if(L.size() >= t.size()) {
                isFind = true;
                for(int i = 0; i < tsize; i++) {
                    if(L[lsize-tsize+i] != t[i]) {
                        isFind = false;
                        break;
                    }
                }
            }
            if(isFind) {
                for(int i = 0; i < tsize; i++) {
                    L.pop_back();
                }
                isLeft = false;
            }
        } else {
            char temp = s.back();
            R.push_back(temp);
            s.pop_back();
            int rsize = R.size();
            int tsize = t.size();
            bool isFind = false;
            if(R.size() >= t.size()) {
                isFind = true;
                for(int i = 0; i < tsize; i++) {
                    if(R[rsize-1-i] != t[i]) {
                        isFind = false;
                        break;
                    }
                }
            }
            if(isFind) {
                for(int i = 0; i < tsize; i++) {
                    R.pop_back();
                }
                isLeft = true;
            }
        }
    }
    while(!L.empty()) {
        char temp = L.back();
        L.pop_back();
        R.push_back(temp);
        int rsize = R.size();
        int tsize = t.size();
        bool isFind = false;
        if(R.size() >= t.size()) {
            isFind = true;
            for(int i = 0; i < tsize; i++) {
                if(R[rsize-1-i] != t[i]) {
                    isFind = false;
                    break;
                }
            }
        }
        if(isFind) {
            for(int i = 0; i < tsize; i++) {
                R.pop_back();
            }
        }
    }
    reverse(R.begin(), R.end());
    cout << R << endl;
}

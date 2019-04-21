#include <vector>
#include <iostream>

using namespace std;
//최대 증가 부분 수열 전체 탐색.
int lis(vector<int>& v) {
    if(v.empty()) return 0; //base case: v is empty.
    int ret = 0;
    for(int i = 0; i < v.size(); i++) {
        vector<int> temp;
        for(int j = i+1; j < v.size(); j++)
            if(v[i] < v[j])
                temp.push_back(v[j]);
        ret = max(ret, 1 + lis(temp));
    }
    return ret;
}
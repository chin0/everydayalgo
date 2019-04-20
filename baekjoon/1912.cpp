#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int find_max(vector<int> list)
{
    int max_cur;
    int max_g = max_cur = list[0];
    for(int i = 1; i < list.size(); i++){
        max_cur = max(list[i], max_cur + list[i]);
        max_g = max(max_cur,max_g);
    }
    return max_g;
}

int main()
{
    int n,temp;
    vector<int> list;

    cin >> n;
    for(int i = 0; i < n; i++){
        cin >> temp;
        list.push_back(temp);
    }

    cout << find_max(list) << endl;
    return 0;
}
    
    

#include <iostream>
#include <cassert>
#include <algorithm>
#include <vector>
using namespace std;

void SevenDwarfs(vector<int> &dwarfs, int sum)
{
    bool isRemoved = false;
    for(vector<int>::iterator iter=dwarfs.begin(); iter != dwarfs.end(); iter++) {
        for(vector<int>::iterator jter=dwarfs.begin(); jter != dwarfs.end(); jter++)
            if( *iter + *jter == sum - 100 && iter != jter){
                dwarfs.erase(jter);
                isRemoved = true;
                break;
            }
        if(isRemoved){ dwarfs.erase(iter); break; }
    }
    sort(dwarfs.begin(), dwarfs.end());
}

int main()
{
    int sum = 0;
    vector<int> dwarfs;

    for(int i = 0; i < 9; i++){
        int temp = 0;
        cin >> temp;
        assert(temp <= 100 && temp > 0);
        sum += temp;
        dwarfs.push_back(temp);
    }
    SevenDwarfs(dwarfs, sum);

    for(vector<int>::iterator iter = dwarfs.begin(); iter != dwarfs.end(); iter++)
        cout << *iter << endl;
    return 0;
}
    
        

    



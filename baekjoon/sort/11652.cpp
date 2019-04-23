#include <stdio.h>
#include <vector>
#include <algorithm>

using namespace std;

using ull = long long int;
int main(void)
{
    ull result, temp;
    int n,count,current;
    vector<ull> v;

    scanf("%d",&n);
    for(int i = 0 ; i < n; i++) {
        scanf("%lld",&temp);
        v.push_back(temp);
    }

    sort(v.begin(),v.end());
    count = 1; 
    current = 1;
    result = v[0];
    for(int i =1; i < n; i++) {
        if(v[i] != v[i-1]) {
            count = 1;
        } else {
            count++;
        }
        if(count > current) {
            result = v[i];
            current = count;
        }
    }
    printf("%lld\n",result);
}
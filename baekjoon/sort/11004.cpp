#include <cstdio>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
    int n,k,temp;
    vector<int> v;

    scanf("%d %d",&n,&k);
    for(int i = 0; i < n; i++) {
        scanf("%d",&temp);
        v.push_back(temp);
    }
    sort(v.begin(), v.end());
    printf("%d\n",v[k-1]);
}
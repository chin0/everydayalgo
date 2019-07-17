//일찍 끝나는 순서대로 배정해버리자!

#include <cstdio>
#include <utility>
#include <vector>
#include <algorithm>

using namespace std;

int main(void)
{
    int start,end,n;
    vector<pair<int,int> > arr;
    
    scanf("%d",&n);
    for(int i = 0; i < n; i++) {
        scanf("%d %d", &start, &end);
        arr.push_back(make_pair(end,start));
    }
    sort(arr.begin(), arr.end());
    int now = 0;
    int ans = 0;
    for(int i = 0; i < arr.size(); i++) {
        if(now <= arr[i].second) {
            now = arr[i].first;
            ans += 1;
        }
    }
    printf("%d\n",ans);
    return 0;
}

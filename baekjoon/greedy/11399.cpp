///오름차순으로 정렬하고 누적합 ㄱ
// 증명 정말 쉬우니 꼭 복습해볼것.
#include <cstdio>
#include <vector>
#include <algorithm>

using namespace std;

int main(void)
{
    int n,temp;
    vector<int> v;

    scanf("%d",&n);
    for(int i = 0; i < n; i++) {
        scanf("%d",&temp);
        v.push_back(temp);
    }
    sort(v.begin(), v.end());

    int sum=0;
    int ans=0;
    for(int i = 0; i < n; i++) {
        sum += v[i];
        ans += sum;
    }
    printf("%d\n",ans);
}

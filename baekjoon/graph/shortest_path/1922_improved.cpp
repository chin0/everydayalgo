//이게 ppt에서 설명한 방식인데 어차피 큐에서 n-1개를 선택한다는게 보장되어있으니까 걍 큐가 빌때까지 하고 같은거 나오면 pop하는 방식
// 처음 코드와 달리 시작과 끝점을 저장하지 않음.
#include <utility>
#include <cstdio>
#include <vector>
#include <queue>
using namespace std;
vector<pair<int,int>> a[1001];
bool c[1001];
int main() {
    int n,m;
    scanf("%d %d",&n,&m);
    for (int i=0; i<m; i++) {
        int t1,t2,t3;
        scanf("%d %d %d",&t1,&t2,&t3);
        a[t1].push_back(make_pair(t2,t3));
        a[t2].push_back(make_pair(t1,t3));
    }
    c[1] = true;
    priority_queue<pair<int,int>> q;
    for (auto &p : a[1]) {
        q.push(make_pair(-p.second,p.first));
    }
    int ans = 0;
    while (!q.empty()) {
        auto p = q.top();
        q.pop();
        if (c[p.second]) continue;
        c[p.second] = true;
        ans += -p.first;
        int x = p.second;
        for (auto &p : a[x]) {
            q.push(make_pair(-p.second,p.first));
        }
    }
    printf("%d\n",ans);
    return 0;
}


#include <iostream>
#include <cstdio>
#include <vector>
#include <queue>
#include <utility>

using namespace std;

vector<pair<int,int>>  a[10001]; //원래 방향 간선리스트 
vector<pair<int,int>> b[10001]; //역방향 간선리스트

int ind[10001];//원래방향 indegree
int ind2[10001]; //역방향 indegree
int d[10001];
bool c[10001];

int main()
{
    int n,m;
    scanf("%d %d", &n, &m);

    for(int i = 0; i < m; i++) {
        int t1,t2,t3;
        scanf("%d %d %d", &t1,&t2,&t3);
        a[t1].push_back(make_pair(t2,t3));
        a[t2].push_back(make_pair(t1,t3));
        ind[t2] += 1;
        ind2[t1] += 1;
    }
    int st,ed;
    scanf("%d %d", &st, &ed);

    queue<int> q;
    for(int i =1; i <= n; i++) {
        if(ind[i] == 0) {
            q.push(i);
        }
    }

    while(!q.empty()) {
        int x = q.front();
        q.pop();
        for(int k = 0; k < a[x].size(); k++) {
            int y = a[x][k].first;
            d[y] = max(d[y], d[x]+a[x][k].second);
            ind[y] -= 1;
            if(ind[y] == 0)
                q.push(y);
        }
    }
    printf("%d\n", d[ed]);
    for(int i = 1; i <= n;i++)
        ind[i] = ind2[i];
    int ans = 0;
    c[ed] = true;
    for(int i = 1; i <= n; i++) {
        int x = q.front();
        q.pop();
        for(int k = 0; k < b[x].size(); k++) {
            int y=b[x][k].first;
            if(c[x] && d[x]- d[y] == b[k][k].second) {
                c[y]= true;
                ans += 1;
            }
            ind[y] -= 1;
            if(ind[y] == 0)
                q.push(y);
        }
    }
    printf("%d\n",ans);
    return 0;
}

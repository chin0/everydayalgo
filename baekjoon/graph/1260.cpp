#include <stdio.h>
#include <stack>
#include <queue>
#include <algorithm>

using namespace std;

bool visited[1001];
bool graph[1001][1001];

void bfs(int v,int n) {
    fill(visited, visited+n+1, false);
    queue<int> s;
    s.push(v);
    while(!s.empty()) {
        int current = s.front();
        s.pop();
        if(visited[current]) continue;
        visited[current] = true;
        printf("%d ", current);
        for(int i = 1; i <= n; i++) {
            if(graph[current][i])
                s.push(i);
        }
    }
    printf("\n");
}

void dfs(int v,int n) {
    fill(visited, visited+n+1, false);
    stack<int> s;
    s.push(v);
    while(!s.empty()) {
        int current = s.top();
        s.pop();
        if(visited[current]) 
            continue;
        printf("%d ",current);
        visited[current] = true;
        for(int i = n; i > 0; i--) {
            if(graph[current][i]) {
                s.push(i);
            }
        }
    }
    printf("\n");
}

int main(void)
{
    int n,m,v;
    scanf("%d %d %d", &n, &m, &v);
    for(int i = 0; i < m; i++) {
        int s,e;
        scanf("%d %d", &s, &e);
        graph[s][e] = graph[e][s] = true;
    }
    dfs(v,n);
    bfs(v,n);
}
#include <stdio.h>
#include <vector>

using namespace std;

struct disjoint_set {
    vector<int> id;
    vector<int> parent;
    vector<int> rank;
    
    //MakeSet operation
    disjoint_set(int n) {
        for(int i = 0; i <= n; i++) {
            id.push_back(i);
            parent.push_back(i);
            rank.push_back(0);
        }
    }

    //find algorithm with path compression
    int find(int id) {
        //만약 자기의 부모 노드가 자기 자신이라면 그 노드는 루트노드임.
        if(parent[id] != id)
            parent[id] = find(parent[id]);
        return parent[id];
    }

    void uni(int x, int y) {
        int xroot = find(x);
        int yroot = find(y);

        if(xroot == yroot)
            return;
        
        if(rank[xroot] < rank[yroot]) {
            int temp = xroot;
            xroot = yroot;
            yroot = temp;
        }

        parent[yroot] = xroot;
        if(rank[xroot] == rank[yroot]) {
            rank[xroot] += 1;
        }
    }

    bool in_same_set(int x, int y) {
        return find(x) == find(y);
    }
};
int main()
{
    int n,m,op,x,y;

   scanf("%d %d",&n,&m);
    disjoint_set s(n);
    vector<bool> anwser;

    for(int i = 0; i < m; i++) {
        scanf("%d %d %d",&op, &x, &y);
        if(op == 0) {
            s.uni(x,y);
        } else if(op == 1) {
            anwser.push_back(s.in_same_set(x,y));
        }
    }
    for(int i = 0; i < anwser.size(); i++) {
        if(anwser[i])
            printf("YES\n");
        else
            printf("NO\n");
    }
}
#include <iostream>
#include <vector>
using namespace std;

struct union_find {
    vector<int> parent, rank;
    union_find(int n) {
        for(int i = 0; i < n; i++) {
            parent.push_back(i);
            rank.push_back(0);
        }
    }
    int find(int x) {
        int root = parent[x];
        while(root != parent[root])
            root = parent[root];
        parent[x] = root;
        return root;
    }
    void merge(int x, int y) {
        int xroot = find(x);
        int yroot = find(y);

        if(xroot == yroot)
            return;
        
        if(rank[xroot] > rank[yroot])
            parent[yroot] = xroot;
        else if(rank[yroot] > rank[xroot])
            parent[xroot] = yroot;
        else {
            parent[yroot] = xroot;
            rank[xroot]++;
        }
    }
};

int main(void) {
    int n,m,x,y,op;
    cin >> n >> m;
    union_find uf(n);
    for(int i = 0; i < m; i++) {
        cin >> op >> x >> y;
        if(op == 0) {
            uf.merge(x,y);
        } else if (op == 1) {
            if(uf.find(x) == uf.find(y))
                cout << "YES" << endl;
            else
                cout << "NO" << endl;
        }
    }
}
            




#include <cstdio>
#include <vector>

using namespace std;

bool selected[8];

int cnt;

void solve(int m, vector<int> &v) {
    if(m == 0) {
        for(auto i : v) {
            printf("%d ", i);
        }
        printf("\n");
        return;
    } 
    for(int i = 0; i < cnt; i++) {
        selected[i] = true;
        v.push_back(i+1);
        solve(m-1,v);
        v.pop_back();
        selected[i] = false;
    }
}

int main(void) {
    int m;
    scanf("%d %d", &cnt, &m);
    
    vector<int> v;
    solve(m, v);
}

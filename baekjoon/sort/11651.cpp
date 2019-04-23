#include <cstdio>
#include <vector>
#include <algorithm>

using namespace std;

struct point {
    int x;
    int y;
};

bool comp(const point &p1, const point &p2) {
    if(p1.y == p2.y) {
        return p1.x < p2.x;
    } else {
        return p1.y < p2.y;
    }
}

int main() {
    int n,x,y;
    vector<point> v;

    scanf("%d",&n);
    for(int i = 0; i < n; i++) {
        scanf("%d %d", &x, &y);
        v.push_back({x,y});
    }
    sort(v.begin(),v.end(),comp);
    for(int i = 0; i < n; i++) {
        printf("%d %d\n",v[i].x, v[i].y);
    }
}
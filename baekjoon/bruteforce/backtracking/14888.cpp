#include <cstdio>
#include <vector>
#include <algorithm>

using namespace std;

bool selected[8];

int cnt;

long long ans=-1000000001,ans2 = 1000000001;
void solve(int m, vector<int> &v, vector<int> &value,vector<int>& opcount) {
    if(m == 0) {
        long long result = value[0];
        for(int i = 0; i < v.size(); i++) {
            switch(v[i]) {
            case 0:
                result += value[i+1];
                break;
            case 1:
                result -= value[i+1];
                break;
            case 2:
                result *= value[i+1];
                break;
            case 3:
                result /= value[i+1];
                break;
            }
        }
        ans = max(ans,result);
        ans2 = min(ans2,result);
    } 
    for(int i = 0; i < 4; i++) {
        if(opcount[i] != 0) {
            v.push_back(i);
            opcount[i] -= 1;
            solve(m-1,v,value,opcount);
            opcount[i] += 1;
            v.pop_back();
        }
    }
}

int main(void) {
    scanf("%d", &cnt);
    
    vector<int> v,a,op;

    for(int i = 0; i < cnt; i++) {
        int temp;
        scanf("%d", &temp);
        a.push_back(temp);
    }
    for(int i = 0; i < 4; i++) {
        int temp;
        scanf("%d", &temp);
        op.push_back(temp);
    }
    solve(cnt-1,v,a,op);
    printf("%lld\n%lld\n",ans,ans2);
}

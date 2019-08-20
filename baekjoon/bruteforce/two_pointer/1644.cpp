#include <iostream>
#include <vector>

using namespace std;

int main(void)
{
    int n;
    cin >> n;
    vector<int> p;
    vector<bool> c(n+1);

    for(int i = 2; i <= n; i++) {
        if(!c[i]) {
            p.push_back(i);
            for(int j = i*2; j <= n; j+=i) {
                c[j] = true;
            }
        }
    }
    int left=0,right=0;
    int ans = 0;
    //n = 1일때 
    int sum = (p.empty()) ? 0 : p[0];
    while(left <= right && right < p.size()) {
        if(sum < n) {
            right++;
            sum += p[right];
        } else if(sum == n) {
            ans++;
            right++;
            sum += p[right];
        }else {
            sum -= p[left];
            left++;
        }
    }
    cout << ans << endl;
}

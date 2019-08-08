#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int main()
{
    int n;
    vector<int> plus;
    vector<int> minus;

    cin >> n;

    int zero = 0;
    int one = 0;

    for(int i = 0; i < n; i++) {
        int x;
        cin >> x;
        if(x == 1) {
            one += 1;
        } else if(x > 0) {
            plus.push_back(x);
        } else if(x < 0) {
            minus.push_back(x);
        } else {
            zero += 1;
        }
    }

    sort(plus.begin(), plus.end());
    reverse(plus.begin(), plus.end());
    sort(minus.begin(), minus.end());
    //어차피 1이 들어간다고 달라지지 않으니까 2개씩 묶기 위하여 1추가.
    if(plus.size() % 2 == 1) {
        plus.push_back(1);
    }
    //0이 있는 경우에 안묶이는 음수를 0과 묶어서 0으로 만들수있음.
    if(minus.size()%2 == 1) {
        minus.push_back(zero > 0 ? 0 : 1);
    }

    int ans = one;
    for(int i = 0; i < plus.size(); i+=2) {
        ans += plus[i] * plus[i+1];
    }

    for(int i = 0; i < minus.size(); i += 2) {
        ans += minus[i] * minus[i+1];
    }
    cout << ans << '\n';
    return 0;
}

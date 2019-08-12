#include <iostream>

using namespace std;

bool broken[10];

int possible(int c)
{
    //0인 경우는 while문에 안걸리기때문에 따로 처리
    if(c == 0) {
        return broken[0] ? 0 : 1;
    }

    int len = 0;
    while(c > 0) {
        if(broken[c % 10]) {
            return 0;
        }
        len += 1;
        c /= 10;
    }
    return len;
}

int main()
{
    int n;
    cin >> n;
    int m;
    cin >> m;
    for(int i = 0; i < m; i++) {
        int x ;
        cin >> x;
        broken[x] = true;
    }
    int ans = n - 100;
    if(ans < 0) {
        ans = -ans;
    }
    //왜 500000이 아니냐면 입력으로 주어지는건 500000까지이지만 최선의 경우는 500000만보다 더 큰 채널을 눌러야할수도 있음.
    // 500000에서 5와 1만 쓸수있는 경우를 생각해보자.
    // 이런 이유로 1000000번까지 테스트 하는걸로 정했음.
    for(int i = 0; i <= 1000000; i++) {
        int c = i;
        int len = possible(c);
        if(len > 0) {
            int press = c - n;
            if(press < 0) {
                press = -press;
            }
            if(ans > len + press)
                ans = len + press;
        }
    }
    printf("%d\n",ans);
}

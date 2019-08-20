#include <cstdio>
#include <string>

using namespace std;

int main(void)
{
    int n,cnt =0;
    scanf("%d",&n);

    for(int i = 1; i <= n; i++) {
        string s = to_string(i);
        bool flag = true;
        int d = s[1] - s[0];
        for(int i = 2; i < s.length(); i++) {
            if(s[i] - s[i-1] != d){
                flag = false;
                break;
            }
        }
        if(flag) cnt++;

    }
    printf("%d\n",cnt);
}

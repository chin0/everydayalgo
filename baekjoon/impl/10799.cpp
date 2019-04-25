#include <string>
#include <iostream>

using namespace std;

int main(void)
{
    int c = 0, split = 0,result = 0;
    string s;
    ios::sync_with_stdio(false);

    cin >> s;

    for(int i = 0; i < s.length(); i++) {
        if(s[i] == '(') {
            c++;
        }
        if(s[i] == ')') {
            c--;
            if(s[i-1] == '(') {
                result += c;
            } else { //파이프가 끝날때 잘리는거 1개.
                result += 1; 
            }
        }
    }
    printf("%d\n",result);
}
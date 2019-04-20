#include <stdio.h>
#include <string.h>
#include <algorithm>
#include <functional>
using namespace std;
//귀찮아서 걍 대충 구현함 ㅇㅇ
//관계식: k의 부모: [k/2].([]는 최대정수함수)
//k의 자식: 2k, 2k+1
char buf[12];
int main(void) {
    scanf("%s",buf);
    int len = strlen(buf);
    sort(buf, buf+len,greater<int>());
    printf("%s\n",buf);
}

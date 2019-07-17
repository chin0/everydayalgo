#include <stdio.h>

int main(void)
{
    int mday[]= {31,28,31,30,31,30,31,31,30,31,30,31};
    char* day_s[] = {"SUN","MON","TUE","WED","THU","FRI","SAT"};

    int m,d,cnt=0;
    scanf("%d %d",&m, &d);

    for(int i = 0; i < m-1;i++) {
        cnt += mday[i];
    }
    cnt += d;
    printf("%s\n",day_s[cnt % 7]);
}

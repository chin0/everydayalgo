#include <cstdio>
#include <cstring>

int dp[5000];
char data[5000];

int main(void)
{
    int current;
    scanf("%s",data);

    if(data[0] == '0') {
        printf("0\n");
        return 0;
    }

    dp[0] = 1;
    dp[1] = (data[1] == '0') ? 0 : 1;
    current = 10 * (data[0] - '0') + (data[1] - '0');
    if(current >= 10 && current < 27) {
        dp[1] += 1;
    } 
    for(int i = 2; i < strlen(data); i++) {
        current = 10 * (data[i-1] - '0') + (data[i] - '0');
        if(data[i] != '0') {
            dp[i] = dp[i-1] % 1000000;
        }
        if(current >= 10 && current < 27) {
            dp[i] = (dp[i] + dp[i-2]) % 1000000;
        } 
    }
    printf("%d\n",dp[strlen(data)-1]);
}
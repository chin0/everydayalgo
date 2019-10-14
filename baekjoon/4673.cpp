#include <iostream>

bool hasGen[10001];

void findGen(int s) {
    do {
        int temp = s;
        while(temp > 0) {
            s += temp % 10;
            temp /= 10;
        }
        hasGen[s] = true;
    } while(s < 10000);
}
int main(void)
{
    for(int i = 1; i< 10000; i++) {
        if(!hasGen[i]) {
            findGen(i);
        }
    }

    for(int i = 1; i < 10000; i++) {
        if(!hasGen[i]) {
            printf("%d\n", i);
        }
    }
}

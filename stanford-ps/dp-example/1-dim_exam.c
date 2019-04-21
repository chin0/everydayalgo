#include <stdio.h>

//given n, find the number of different ways to write n as the sum of 1,3,4
int D[100000];
int bottom_up(int n){
    D[0] = D[1] = D[2] = 1;
    D[3] = 2;
    for(int i = 4; i <= n; i++) {
        D[i] = D[i-1] + D[i-3] + D[i-4];
    }
    return D[n];
}

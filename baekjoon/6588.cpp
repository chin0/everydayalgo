#include <stdio.h>
#include <algorithm>

void sieve(int arr[], int n) {
    std::fill_n(arr,n,1);
    arr[0] = 0;
    arr[1] = 0;
    for(int i = 2; i*i <= n; i++) {
        if(arr[i]) {
            for(int j = i*2; j <= n; j+=i) {
                arr[j] = 0;
            }
        }
    }
}

int main(void) {
    int n;
    int arr[1000000];

    sieve(arr, 1000000);

    do {
        scanf("%d",&n);
        for(int i = 3; i < n; i+=2) {
            if(arr[i] && arr[n-i]) {
                printf("%d = %d + %d\n", n, i, n-i);
                break;
            }
        }
    } while(n);

    return 0;
}
#include <stdio.h>

//귀찮아서 걍 대충 구현함 ㅇㅇ
//관계식: k의 부모: [k/2].([]는 최대정수함수)
//k의 자식: 2k, 2k+1
char H[1000000000]; //array for heap
int n = 0; //heap size
void swap(char &a, char &b) {
    char temp = a;
    a = b;
    b = temp;
}

void InsertNode(int v) {
    H[++n] = v;
    for(int k = n; k > 1; k/=2) {
        if(H[k] < H[k/2]) //if new node breaks rule...
            swap(H[k], H[k/2]); //swap with its parent
        else break;
    }
}

int DeleteNode() {
    int ret = H[1]; //bring the root node.
    H[1] = H[n--];

    for(int k = 1; 2*k <= n;) {
        if(H[k] < H[k*2] && H[k] < H[k*2 + 1]) {
            break;
        }
        if(H[k*2] < H[k*2 + 1]) {
            swap(H[k], H[k*2]);
            k = 2 * k;
        } else {
            swap(H[k], H[k*2 + 1]);
            k = 2 * k + 1;
        }
    }

    return ret;
}

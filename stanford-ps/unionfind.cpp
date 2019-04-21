#include <stdio.h>

int L[1000]; //array for union-find 

int Find(int x) {
    while(x != L[x]) x = L[x];
    return x;
}

void Union(int x, int y) {
    L[Find(x)] = Find(y);
}
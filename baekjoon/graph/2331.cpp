#include <stdio.h>
#include <vector>

using namespace std;

int calc(int n, int p) {
    int ret = 0,t;
    int b = 1;
    while(n / b) {
        t = (n % (b * 10)) / b;
        int e = 1;
        for(int i = 0; i < p; i++) {
            e *= t;
        }
        ret += e;
        b *= 10;
    }
    return ret;
}
int main(void) 
{
    int n,p;
    scanf("%d %d", &n, &p);
    vector<int> list;
    int current = n;
    int res = 0;
    while(1) {
        list.emplace_back(current);
        current = calc(current,p);
        bool is_find = false;
        for(int i = 0; i < list.size(); i++) {
            if(list[i] == current) {
                res = i;
                is_find = true; 
                break;
            }
        }
        if(is_find) break;
    }
     int cnt = 0;
    for(int i = 0; i < res; i++) {
        cnt++;
    }
    printf("%d\n",res);
}

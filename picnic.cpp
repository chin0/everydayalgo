#include <stdio.h>
#include <utility>
#include <vector>

using namespace std;


//friendlist[i][j]가 1이라면 서로 친구.
bool friendlist[10][10];

int picnic(bool selected[10],int n)
{
    int firstFree = -1;
    for(int i = 0; i < n; i++) {
        if(!selected[i]) {
            firstFree = i;
            break;
        }
    }

    if(firstFree == -1) return 1;
    int ret = 0;

    for(int pairWith = firstFree+1; pairWith < n; ++pairWith) {
        if(!selected[pairWith] && friendlist[firstFree][pairWith]) {
            selected[firstFree] = selected[pairWith] = true;
            ret += picnic(selected,n);
            selected[firstFree] = selected[pairWith] = false;
        }
    }
    return ret;
}

int main(void)
{
    int n,m;
    scanf("%d %d",&n,&m);
    for(int i = 0; i < m; i++) {

    }
}

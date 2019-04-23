
//counting sort의 알고리즘을 살짝 개조해서 메모리 초과 해결해야함.
// 간단히 수가 얼마나 나오는지 카운팅하고 누적합을 만들지 않고 count[i]을 앞에서부터
// 순회를 돌고 그 카운트만큼 수를 출력해주면된다.

//counting sort를 얼마나 잘 이해하고 이것을 변형할수있는가를 묻는 문제였음.

#include <stdio.h>
#include <vector>

using namespace std;

int main(void)
{
    int n,temp;
    int count[10001] = {0,};

    scanf("%d",&n);


    for(int i = 0; i < n; i++) {
        scanf("%d",&temp);
        count[temp]++;
    }


    for(int i = 0; i < 10001; i++) {
        if(count[i]) {
            for(int j = 0; j < count[i]; j++) {
                printf("%d\n",i);
            }
        }
    }
}
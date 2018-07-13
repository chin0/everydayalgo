#include <cstdio>
#include <vector>
#include <algorithm>

using namespace std;

/*
comment:
https://lyzqm.blogspot.com/2017/07/10800.html 이 풀이 참고함.
처음에 총합을 이용한 아이디어를 좀 더 구체화 했으면 풀 수 있었을텐데 너무 아쉽다.
처음에는 naive하게 단순 구현해서 돌려보았지만 입력의 최대 크기가 200000이기때문에 O(N^2)
알고리즘으로는 무조건 시간초과다.
따라서 O(N log N)의 알고리즘을 생각할 필요가 있었고, 이때 총합을 이용한 아이디어를 생각하는것이 포인트였다.
합과 관련된 문제에서 이런 아이디어가 속도 단축의 key가 될수있다는것을 기억하자.

간단하게 이 방법을 생각해내는 방법은 정렬 후 20의 크기를 가지는 공의 개수를 구할 수 있다면
10의 크기는 여기서 살짝 빼주면 구할수있다.

나중에 부분합 알고리즘을 이용한 풀이도 다시 올릴것이다.
http://codersbrunch.blogspot.com/2017/01/10800.html
여기는 코드가 꽤 신박하다. 
*/


struct ball {
    int color;
    int size;
    int id;
};

//색깔은 오름차순이고 크기는 내림차순
bool operator<(const ball &x, const ball &y) {
    if(x.size == y.size)
        return x.color < y.color;
    return x.size > y.size;
}

int main()
{
    int n;
    scanf("%d", &n);
    ball player[n];
    int result[n];
    int size_cnt[2001] = {0,};
    int color_sum[200001] = {0,};
    int sum = {0,};

    for(int i = 0; i < n; i++) {
        ball temp;
        temp.id = i;
        scanf("%d %d",&temp.color,&temp.size);
        player[i] = temp;
        size_cnt[temp.size]++;
    }

    //크기 기준 내림차순으로 정렬.
    sort(player, player+n);

    //모든 누적합 구하기.
    for(int i = 0; i < n; i++) {
        sum += player[i].size;
        color_sum[player[i].color] += player[i].size;
    }
    //가장 큰 값부터 답 구하기.
    for(int i = 0; i < n; i++) {
        //상태가 같은 가장 첫번째 노드. 
        int upper = upper_bound(player+i, player + n, player[i]) - player;
        //상태가 다른(색깔이 다르거나 크기가 다른) 가장 첫번째 노드.
        int lower = lower_bound(player+i, player + n, player[i]) - player;
        //upper - lower = 같은 공의 개수.
        //같은 공의 합을 빼고 다른 공의 같은 크기의 공의 합을 뺀다. 같은 공의 개수가 있으니까.
        //그리고 color를 오름차순으로 정렬하는 이유는 그래야 올바른 범위를 구할수있기 때문.(색깔을 제외한)
        result[player[i].id] = sum - (size_cnt[player[i].size] - (upper-lower)) * player[i].size - color_sum[player[i].color];
        //다음 계산을 위해 누적합 갱신.
        sum -= player[i].size;
        color_sum[player[i].color] -= player[i].size;
        size_cnt[player[i].size]--;
    }

    for(int i = 0; i < n; i++) {
        printf("%d\n",result[i]);
    }
    
}
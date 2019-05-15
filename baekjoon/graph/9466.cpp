//dfs로 사이클 체크. isFinished라는 배열을 하나 더 도입하는 아이디어에 주목하자.
//http://blog.naver.com/PostView.nhn?blogId=gunwooyeon&logNo=220942236105&parentCategoryNo=&categoryNo=9&viewDate=&isShowPopularPosts=true&from=search
#include <stdio.h>
#include <algorithm>
#include <vector>

using namespace std;

bool visited[100001], isFinished[100001];
int cnt;
//isFinished라는 배열을 하나 더 도입해서 사이클을 탐지한다.
//cnt는 사이클에 속하는 노드들의 개수.
//return cycle's length
void visit(int start, const int permutation[])
{
    visited[start] = true;
    int next = permutation[start];
    if(!visited[next]) { //한번도 방문한적 없는 노드라면
        visit(next,permutation);
    } 
    else if(!isFinished[next]){ //한번 이상 방문했으면 사이클을 이룬다는 의미. 그러므로 개수를 세준다.
        for(int i = next; i != start; i = permutation[i]) {
            cnt++;
        }
        cnt++;
    }
    isFinished[start] = true; //이제 완전히 방문할 일이 없다. next로 하면 안된다,,,,
    //이 마지막에 finished[start] = true해주는 부분이 사이클에 속한 모든 노드를 방문했다고 체크하는것과 같음.
    // dfs이기 때문에,,
}

int main(void)
{
    int t;
    scanf("%d", &t);

    for(int i = 0; i < t; i++ ) {
        int n;
        scanf("%d", &n);
        fill(visited,visited + n + 1, false);
        fill(isFinished,isFinished + n + 1, false);
        int permutation[n+1];
        for(int j = 1; j <= n; j++) {
            scanf("%d", &permutation[j]);
        }
        cnt = 0;
        for(int j = 1; j <= n; j++) {
            if(!visited[j])
                visit(j,permutation);
        }
        printf("%d\n",n - cnt);
    }
}
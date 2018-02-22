# [topcoder] 다양한 형태의 전체 탐색

## 탐색의 종류

### 깊이 우선 탐색

![DFS](https://upload.wikimedia.org/wikipedia/commons/2/2c/Depthfirst.png)

- 깊이 우선 탐색은 최대한 왼쪽으로 깊게 정점을 탐색함. 자식이 없는 정점까지 탐색하면 가장 가까운 탐색이 끝나지 않은 정점으로 돌아와 탐색을 계속 진행함.

### 너비 우선 탐색

![BFS](https://upload.wikimedia.org/wikipedia/commons/4/46/Animated_BFS.gif)

- 너비 우선 탐색은 왼쪽부터 깊이가 얕은 순서로 차근차근 정점을 탐색함.

### 가지치기

- 탐색에 규칙을 추가시켜서 불필요한 탐색을 줄이는것.

### 구현

- 깊이 우선탐색은 재귀함수를 이용해서 구현한다. 의사코드는 다음과 같다.

```C++
int dfs(int now) {
  if(현재 상태 now가 끝나는 조건) return 현재 상태 now의 값;
  int ret = -1;
  for(int i = 0; i < 다음 상태 개수; i++) {
    int next = i번째 다음 상태;
    if(next가 조건을 만족하는 경우) ret = max(dfs(next),ret);
  }
  return ret;
}
```

- 너비 우선 탐색은 큐를 이용한다.

```c++
Queue<T> q = new Queue<T>();
q.Enqueue(초기 상태);
while(q.Count != 0) 
{
  T now = q.Dequeue();
  현재 상태 처리
  for(int i = 0; i < 다음 상태 개수; i++)
  {
  	T next = i번째 다음 상태;
  	if(next를 방문했었는지 판정)
  	   q.Enqueue(next);
  }
}
```

### 깊이 우선 탐색과 너비 우선 탐색의 차이점

- 깊이 우선 탐색을 사용하면 좋은 경우
  - 모든 경로를 탐색하고 결과를 확인해야하는 경우
  - 문자열등을 검색할때 "사전 순서로 앞에 오는 것"처럼 앞에서 검색해서 찾는것이 빠른경우
- 너비 우선 탐색을 사용하면 좋은 경우
  - 시작 지점에서 가장 가꾸은것을 구하고 싶은 경우.
  - 탐색범위는 넓지만 어느 정도 근처에 구하고 싶은 해가 존재하는 것을 알고 있는 경우
  - 탐색 범위가 굉장히 넓으며 깊이 우선 탐색을 사용할 때는 스택이 대량으로 사용되는 경우.
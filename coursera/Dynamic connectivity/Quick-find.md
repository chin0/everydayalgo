# Quick-find

- 동적 연결성 문제를 해결하는 첫번째 방법.

자료구조

- 크기 N인 Int형 배열 id[] 
- interpretation: p와 q가 연결되어있다면, p,q의 id는 같다.

Find연산 구현: p와 q가 같은 id를 갖고있는지 확인한다.

Union: id가 id[p]인 모든 항목을 id[q] 로 변경해 p와 q의 구성 요소를 합친다.

저번에 정의했던 API대로 코드를 짜보자.

## 구현

1. 생성자

```java
public QuickFindUF(int N)
{
  id = new int[N];
  for(int i = 0; i < N; i++)
  	id[i] = i;
}
```

2. find

```java
public boolean connected(int p, int q) 
{ retrun id[p] == id[q]; }
```

3. Union

```java
public void union(int p, int q)
{
  int pid = id[p];
  int qid = id[q];
  for(int i = 0; i < id.length; i++)
  	if(id[i] == pid) id[i] = qid;
}
```

## Union-find 분석

Cost model: 배열에 접근하는 횟수(읽기,쓰기)

| init | union | find |
| ---- | ----- | ---- |
| N    | N     | 1    |

- Find 연산에서는 배열에 한번만 접근하면 되므로 1.
- union에서는 모든 배열을 순회하므로 N
- init에서도 모든 배열을 순회하므로 N

**문제점**: union 연산이 너무 느리다.

N개의 객체에 대한 총 N개의 Union명령을 처리하려면 N^2번만큼 배열에 접근해야함.

### Quadratic algorithm의 문제점

- Quadratic algorithm?
  - 실행시간이 N^2의 형태인 알고리즘

현재의 대략적인 컴퓨터

- 1초당 10^9개의 연산
- 10^9 word 크기의 메인메모리
- 약 1초만에 모든 word에 접근할수있음.

quick-find의 심각성

- 10^9 union command를 10^9개의 객체에 대해 처리할때,
  - Quick-find 알고리즘은 10^18번의 연산을 하게됨.
  - 고로 현재 컴퓨터 속도로 30년 이상이 걸린다.
  - 앞으로 컴퓨터가 더 좋아진다면, 그에 따라서 해결할 문제도 더 커지기때문에 상황은 비슷할것이다.

**즉, Quadratic algorithm은 기술의 속도를 따라가지 못한다.**


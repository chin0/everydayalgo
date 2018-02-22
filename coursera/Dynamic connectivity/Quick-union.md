# Quick-union

- Lazy approach

## 자료구조

- N크기의 id 배열.
- interpretation : id[i]는 i의 parent(부모)다.
- Root는 자기 자신을 parent로 갖는다.
- i의 root는 id[id[id[...id[i]...]]]이다. 이때 값이 변하지 않을때 까지 계속 반복한다.

![Quick union overview](http://algs4.cs.princeton.edu/15uf/images/quick-union-overview.png)

**Find:** p와 q가 같은 root를 가지고있는지 확인.

**Union:** p와 q를 합치기위해, p의 root의 id를 q의 root의 id로 바꾼다.

## 구현

Constructor

```java
public QuickUnionUF(int N)
{
  id = new int[N];
  for(int i = 0; i < N; i++) id[i] = i;
}
```

connected

```java
public boolean connected(int p, int q)
{
  return root(p) == root(q);
}
```

```java
private int root(int i)
{
  while(i != id[i]) i = id[i];
  return i;
}
```

union

```java
public void union(int p, int q)
{
  int i = root(p);
  int j = root(q);
  id[i] = j;
}
```

## 분석

Cost model: 배열 접근 횟수(union find와 비교)

| algorithm   | init | union               | find      |
| ----------- | ---- | ------------------- | --------- |
| quick-find  | N    | N                   | 1         |
| quick-union | N    | N (root를 찾는데서 비용증가) | N(최악의 경우) |

Quick-find 단점

- Union이 너무 느리다(N번접근)
- Tree는 flat하지만, Tree를 flat하게 만드는데 너무 비용이 큼.

Quick-union 단점

- tree가 세로로 자랄수있음.
- Find가 너무 느림.(최악의 경우 N번반복.)


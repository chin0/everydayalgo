# Union-find applications

Union-find 알고리즘의 응용사례에 대해서 알아본다.

- **Percolation**
- Games(Go,Hex)
- **동적 연결성.**
- Least common ancestor(그래프 문제)
- 유한 상태 오토마타의 항등관계
- 물리학의 Hoshen-Kopelman 알고리즘
- Hindley-Milner polymorphic type inference
- 크루스컬 최소 신장 트리 알고리즘
- 포트란의 동치 구문 컴파일
- Matlab의 이미지 프로세싱의 bwlabel() 함수

## Percolation

많은 물리 시스템을 모델링하는데 사용함.

- N*N의 격자가 있고, 각각의 사각형을 site라고 부른다.
- 각 opened-site는 확률 p blocked-site는 1-p의 확률을 가진다.
- 위쪽과 맨 아래쪽이 open-site로 연결되어있으면, System이 percolate하다고 말한다.

![percolation](http://www.cs.princeton.edu/courses/archive/fall14/cos226/assignments/percolates.png)

이 모델은 다양한 system에 대해서 생각해볼수있는다.

예를들어 전기에 대해서 생각해보자면 빈site는 condutor, 막힌site는 절연된 곳이라고 생각할수있다.

| model              | system     | vacant site | occupied site | percolates   |
| ------------------ | ---------- | ----------- | ------------- | ------------ |
| electricity        | material   | conductor   | insulated     | conducts     |
| fluid flow         | material   | empty       | blocked       | porous       |
| social interaction | population | person      | empty         | communicates |

![asdf](http://introcs.cs.princeton.edu/java/24percolation/images/percolation-visualize.png)

- 이론상 N이 충분히 크면 다음 p*값을 보장함.
  - p > p*인 지점에서는 almost certainly percolate하고,
  - p < p*인 지점에는almost certainly does not percolate하다.
- p*값은 무엇인가?
  - 수학적으로 해결하는 방법은 나오지 않음.
  - 하지만 컴퓨터 시뮬레이션으로 해결하는 방법은 있음!
    - 그것도 union-find로!

## Monte Carlo simulation

- 모든 격자(N*N크기)는 닫혀있게 초기화한다.
- 랜덤한 site를 위와 아래가 open site로 연결될때까지 열어놓는다.
- 연결되면, vacancy percentage가 p*에 대한 추정값이다.


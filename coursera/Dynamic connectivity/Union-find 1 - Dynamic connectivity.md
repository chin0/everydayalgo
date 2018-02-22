# Union-find 1 - Dynamic connectivity

## 목표

- 동적 연결성이라는 문제를 푸는 알고리즘 조사
  - Quick-find
  - Quick-union
- 이 알고리즘의 응용사례와 성능 향상법 조사.

## 좋은 알고리즘을 만드는방법

- 문제를 모델링한다.
  - 문제를 이해하고, 문제를 푸기 위한 중요한 요소들을 무엇인지 이해.
- 알고리즘을 찾고, 문제를 푼다.
- 충분히 빠르고 메모리를 알맞게 사용하는가?
  - 그렇지 않다면 왜 그런지 이해한다.
  - 문제를 일으키는것이 무엇인지 찾는다.
- 반복

**수학적 접근**

- 수학적 모델을 설계하고, 입증하는 실험을 통하여 더 나은 알고리즘을 만드는데 도움이 될수도 있음.

## Dynamic connectivity

- N개의 객체가 있다고 하자.(각 객체에는 0 ~ n-1까지의 번호가 매겨저 있음.)
  - Union: 두 객체를 연결한다.
  - Find/connected: 두 객체를 연결하는 경로가 있는지 조사. - 이 문제의 주요 요소다.

![DC](https://cdn-images-1.medium.com/max/2000/1*QPa28dwWh-g6nxB1Gksvng.png)

## 응용사례

- 사진의 픽셀
- 네트워크
- 소셜네트워크의 친구
- 컴퓨터 칩의 트랜지스터
- 집합의 원소
- 포트란 프로그램의 변수 이름
- 등등

## 모델링

- A가 B에 연결되어 있다를 동치 관계라고 가정한다.
  - 모든 객체는 자신과 연결되어있다.
  - P가 q에 연결되어있으면 p는 q와 연결되어있다.
  - p가 q와 연결되어있고, q와 r이 연결되어있다면, p와 r은 연결되어있다.
- Connected component: 연결된 객체들의 집합으로 객체들의 집합의 subset이다.

## 구현

- Find : 같은 연결 요소(Connected Component)에 있는지 확인.
- Union: 두 연결 요소를 합침.

![DC](https://cdn-images-1.medium.com/max/2000/1*QPa28dwWh-g6nxB1Gksvng.png)

#### API(JAVA)

- UF(int N) - 0 ~ N-1의 객체를 생성함.
- void union(int p, int q) - p와 q의 연결을 추가한다.
- boolean connective(int p, int q) - p와 q가 같은 연결요소에 있는가?


Main function

```java
public static void main(String[] args) {
	// write your code here
        int N = StdIn.readInt();
        UF uf = new UF(N);
        while (!StdIn.isEmpty())
        {
            int p = StdIn.readInt();
            int q = StdIn.readInt();
            if(!uf.connected(p,q))
            {
                uf.union(p,q);
                StdOut.println(p + " " + q);
            }
        }
    }
```







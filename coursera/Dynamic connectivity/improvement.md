# improvement

## improvement 1: weighted quick-union

- 큰 트리와 작은 트리를 합칠때, 항상 큰 트리가 작은 트리의 parent가 되게한다.
- 이를 위해서 tree의 size를 추적한다. 이때 size는 object의 개수이다.

![Weighted quick union overview](http://algs4.cs.princeton.edu/15uf/images/weighted-quick-union-overview.png)

- 이렇게 되면, 어떤 item도 root와 멀리 떨어지지 않게 된다는것을 보장한다. 다음 사진을 보면 이를 증명할수있다.

![wqu](https://s3.amazonaws.com/leighhalliday/manual/weighted-quick-union.png)

### 구현

- quick-union과 비슷하다. 하지만 sz[i]라는 i를 루트로하는 트리의 item개수를 저장할 배열을 추가로 사용한다.
- **find**: quick-union과 동일
- **Union**
  - 작은 트리를 큰 트리에 연결한다.
  - sz[] 배열을 업데이트한다.

```java
int i = root(p);
int j = root(q);
if(i == j) return;
if(sz[i] < sz[j]) { id[i] = j; sz[j] += sz[i]; }
else { id[j] = i; sz[i] += sz[j]; }
```

### 분석

실행시간

- Find: p와 q의 깊이에 비례한다.
- Union: Root가 주어졌을때, 일정한(constant) 시간이 걸림.

Proposition: 모든 노드의 깊이 x는 lg N 이하임.(lg - base-2 logarithm)

-> depth(x) = 3 <= lg N

pf. 언제 x의 깊이가 증가하는가? 바로 크기 T인 트리의 높이가 1이 증가하려면 최소 크기가 T보다 크거나 같은 트리와 합쳐저야함. 즉, 높이가 1이 증가할때마다 트리에 속한 객체의 숫자는 최소 2배가 증가함. N = 2^h => h = lg N.

정리하면,

![img](http://cfile4.uf.tistory.com/image/224A494B583A1B052E1F71)![asdf](![img](http://cfile4.uf.tistory.com/image/224A494B583A1B052E1F71))

## improvement 2: path compression

- p의 루트를 계산한 후.조사한 각 노드의 id를 그 노드의 root로 바꾼다.

### 구현

- 2단계 구현
  - 두번째 루프를 root에 추가하여 검사할 각 노드의 id를 루트로 설정함.

```java
public int find(int p) {
    validate(p);
    int root = p;
    while (root != parent[root])
        root = parent[root];
    while (p != root) {
        int newp = parent[p];
        parent[p] = root;
        p = newp;
    }
    return root;
} 
```

- 단순한 one-pass 변형

  - 경로의 있는 모든 노드가 해당 노드의 조부모를 가리키게 한다.(그러면 경로 길이가 반으로 줄어든다.)

  - ```java
    private int root(int i)
    {
    	while(i != id[i])
    	{
          id[i] = id[id[i]];
          i = id[i];
    	}
    	return i;
    }
    ```

### 분석

- N개의 객체가 있을때, M번의 union 또는 find연산을 했을때, 최대  c(N+M lg* N)번만 배열에 접근한다.
- lg *N은 iterated log function이라고 불리는 함수인데, log 함수를 반복해서 적용했을때의 값으로, 증가 속도 는 매우 느리다.
  - ![img](https://wikimedia.org/api/rest_v1/media/math/render/svg/27016f1fac53950f239303151d7f0d6fb1b56970)

| *x*             | lg* *x* |
| --------------- | ------- |
| (−∞, 1]         | 0       |
| (1, 2]          | 1       |
| (2, 4]          | 2       |
| (4, 16]         | 3       |
| (16, 65536]     | 4       |
| (65536, 265536] | 5       |

- 이론적으로 WQUPC(weighted quick union with path compression)은 선형은 아니다. 그리고 union-find에 대한 선형-시간 알고리즘이 없다는 것이 증명되어 있다. 하지만 log* N의 증가 속도가 극히 느리기 때문에, 현실에서 사용할 때는 선형이라고 표현해도 무리가 없을 정도이다.



## 결론

- 슈퍼컴퓨터보다 좋은 알고리즘이 더 낫다.

![ㅁㄴㅇㄹ](http://cfile8.uf.tistory.com/image/263BB84658ADA21922FDAB)


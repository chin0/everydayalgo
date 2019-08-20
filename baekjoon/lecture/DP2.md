# 다이나믹 프로그래밍 2

- 여기서는 테이블을 채우는 순서를 강조함.
- 문제의 답에 중요한 정보를 이용하여 점화식을 세우는것도 강조함.

## 이동하기

- 테이블을 채우기 위한 순회 순서도 코딩에 꽤 많은 영향을 끼친다.
- a\[i]\[j]는 미로.

### 방법1

- 누구나 다 아는 그 방법. (i,j)에 올수있는 경우의 수를 생각.
- d\[i][j]를 d\[i][j]까지의 최대 사탕 수라고 하면
- d\[i]\[j] = max(dp\[i-1][j],dp\[i][j-1],dp\[i-1][j-1]) + a\[i]\[j] 라는 점화식이 나옴.
- 왜냐하면 (i,j)까지 오는데 가능한 방법이 (i-1,j), (i,j-1),(i-1,j-1) 이 세가지 방법밖에 없기 때문.

### 방법2

- 어디를 갈수있는지를 생각해보자.
- d의 의미는 같음.
- (i,j)에서 (i+1,j),(i,j+1),(i+1,j+1)로 갈수있음.
  - d\[i+1]\[j] = max(d\[i+1]\[j], d\[i+1][j] + a\[i+1][j])
  - d\[i]\[j+1] = max(d\[i]\[j+1], d\[i][j+1] + a\[i]\[j+1])
  - d\[i+1]\[j+1] = max(d\[i+1]\[j+1], d\[i+1][j+1] + a\[i][j+1])
- max를 씌우는 이유는 중복방문이 있기 때문임.
- 1과 2는 점화식이 사실상 같기 때문에 d배열의 값은 같음.

### 방법3

- 생각해보면 대각선 이동은 처리하지 않아도 됨.
- 대각선 이동하는것보다 방문하려는 칸의 윗칸에서 내려오거나 왼쪽에서 오는 방법이 더 크다는것은 생각해보면 자명함.
- 사탕의 개수가 음수가 될수없기 때문에 대각선 이동이 의미가 없어진단 이야기임.
- 따라서 방법1에서 대각선 처리만 빼도 잘 됨.

### 방법4

- 바텀업에서 탑다운.(재귀함수)
- 걍 재귀함수로 바꾼거임.
- 재귀함수를 설계해듯이 하되, 메모이제이션을 적용.

### 방법5

- 이번엔 점화식의 정의를 바꿔보자.
- d\[i]\[j] = (i,j)에서 (N,M)까지의 최대 사탕의 개수로 정의를 바꿔주고 점화식 세워서 조지면 댐 하와와

## 팰린드롬?

- 재밌는 문제.
- for문을 사용해서 테이블을 채우기 귀찮으면 탑다운을 이용해보자.
- d\[i][j] = 1이면 i~j까지 회문, 0이면 아니라고 하자.
- 그러면 자명하게 d\[i][i] = 1이고 d[i]\[i+1]은 두 문자가 같을때 1이 되게 댐.
  - 그러면 3이상의 부분문자열부터는 첫문자와 끝 문자가 같고 나머지가 회문이면 댐. 따라서 점화식은
    - A[i] == A\[j]이고 D\[i+1][j-1] = 1일때 D\[i][j] = 1이라고 할수있다.
- 바텀업방식은 길이를 기준으로 채워주면 댐.
  - 길이 1부터 채우고 그 다음 2, 그 다음 3, 이런식으로

## 팰린드롬 분할

- 팰린드롬인지 아닌지를 알아야하므로 전에 풀었던 팰린드롬? 문제의 점화식을 c라고 하고 재탕하자.
- d\[i] = i까지의 팰린드롬 최소 분할수라고 두면 점화식은 다음과 같다.
  - (j,i)가 팰린드롬이면 D[i] = min(D[j-1]) + 1 

## 동전 1

- 중복된 결과를 제외하는게 중요
  - 1,2,3더하기 문제와는 다르게 3+ 1과 1 + 3은 같은 경우로 처리함.
  - 따라서 이러한 중복 문제를 해결하기 위해서
    - N = 1*x + 2 * y + 3 * z로 했을때 (x,y,z)의 쌍의 개수를 찾는 문제로 바꿔버릴수 있음. 이러면 중복세기 문제가 해결댐.
    - 즉 꼴이나 순서를 일정하게 만들어서 중복을 없애자는 이야기.
- 따라서 어떤 '동전'을 먼저 선택하고 그 다음 어떤 수를 채울지 결정해보자.
- A\[i]를 동전의 가치라고 하고 D\[i]를 최대 동전 수라고 하고 M을 동전의 개수라고 하면, 1,2,3더하기에서는 다음과 같이 채울 값을 먼저 정하고 그 다음 테이블을 채웠음,

```c
for(int i = 1; i <= N; i++) {
	for(int j = 0; j < M; j++) {
		D[i] += D[i - A[j]];
	}
}
```

- 이제 여기서 바깥 for문과 안쪽 for문만 바꿔주면 됨. 즉, j로 어떤 동전을 먼저 선택하고 테이블을 채우는거임. 이러면 
  - A\[0]으로 1을 만드는 방법,, A\[0]으로 2를 만드는 방법,, A\[0]으로 3을 만드는 방법 … 이렇게 먼저 차고
  - A\[1]으로 1을 만드는 방법  A\[1]으로 2을 만드는 방법 .. 이런식으로 차게 되는데 직접 해보면 이게 서로 순서가 바뀌는 경우를 세지 않는다는것을 알수있음.
  - 이게 즉 (A[0] + A[0] + A[0]) + (A[1] + A[1] + A[1]) .. 이런식으로 묶을수 있게끔 테이블을 채우자는거임.

```
for(int j = 1; j < M; j++) {
	for(int i = 0; i <= N; i++) {
		D[i] += D[i - A[j]];
	}
}
```

- 핵심은 이렇게 테이블을 채우는 전략만 잘 생각해도 문제를 쉽게 풀수 있다는거임.

## 동전 2

- 걍 동전 1이랑 비슷한데 최소임 ㅇㅇ

## 내리막길

- 바텀업으로 풀려면 칸을 제일 낮은 값을 갖는 칸부터 채우면 댐.
  - 이게 왜 되냐면 생각해보면 n,m은 모든 칸중에서 가장 낮은 값이여야 그 칸에 방문할수있기 때문임.
  - n,m까지의 경로는 모두 적어보면 내림차순의 수가 될것이고 가장 마지막수는 n,m이기 때문이다.
  - 엄밀한 증명은 좀만 생각해보면 나올것같은데 귀찮으니까 생략 ㅎ
- 바텀업이 무조건 탑다운보다 빠른게 아니다!
  - 바텀업으로 칸을 채우려면 '정렬'후 가장 낮은 칸부터 전부 '다'방문하기 때문에 방문할 필요가 없는 칸도 방문하게 댐.
  - 탑다운은 안그럼.
  - 게다가 정렬까지 필요해서 시간복잡도는 더 큼.

## 구간 나누기

- 이 문제의 핵심은 '조건'을 잘 반영해서 점화식 세우고 코드짜야함.
  - 3번 조건의 예외처리가 꼭 코드에 반영되어야 할것.
- 대체로 dp의 의미는 구하고자하는 답과 동일한 문장이 되는 경우가 대부분임. 뭐 가끔 아닌것들도 있긴 있지만?

## 자두나무

```
두 개의 나무는 그다지 멀리 떨어져 있지 않기 때문에, 자두는 하나의 나무 아래에 서 있다가 다른 나무 아래로 빠르게(1초보다 훨씬 짧은 시간에) 움직일 수 있다. 하지만 자두는 체력이 그다지 좋지 못해서 많이 움직일 수는 없다.
```

- 이 부분때문에 1초 이전에 1번 움직여서 2번에서 시작할수있다는 사실을 알아야댐.
- 그래서 호출을 go(1,0),go(1,1)로 '두번'해줘야함. 이 부분때문에 엿먹는 경우가 꽤 많을듯.

## 고층 빌딩

- 문제를 사실상 같지만 더 풀기 쉽게 바꿔서 푸는 유형
- 여기서는 높이 1인 빌딩이 어디에 있는가?를 아이디어로 해서 풀음.

## 타일 코드

- 생각해보면 2XN의 타일의 배열들이 모인 집합을 생각해보면 약간 배열이 대칭인것과 대칭이 아닌것들의 비율이 1:2정도 될것같음.
  - 따라서 대칭인것들을 구하고 2배시켜서 /2를 시키면 어떨까?
- ㄹㅇ 개쩌는 아이디어네
- 코드상으로는 대칭을 포함한 개수를 샌 다음 따로 대칭을 구하고 그것을 더해준 후에 2로 나눔.

## 기타리스트

- 펠린드롬?문제의 아이디어를 응용해보자.
- d\[i][j]를 i번째 곡을 볼륨 j로 연주할수있으면 1, 아니면 0이라고 하자.
- 그러면 d\[i][j] = 1이면 d\[i+1][j-v[i+1]] 와 d\[i+1][j+v[i+1]]를 1으로 만들수 있음.

## 1학년

- 팰린드롬?의 응용
- d\[i][j]를 i번째 수까지 사용해서 j를 만드는 경우의 수라고 하자.
- d\[i][j] = d\[i-1][j+a[i]] + d\[i-1][j-a[i]]

## 올바른 괄호 문자열

- 짝이 맞아야하기 때문에 파일 합치기의 다이나믹이랑 비슷함.
- 즉, 짝이 맞는 k를 찾고 그 k를 기준으로 나누어지는 구간으로 다이나믹을 하는 부분이 비슷함.

## 같은 탑

- dp\[N][D]= 높은탑과 낮은 탑의 공통 길이, D= 높은탑과 낮은 탑의 차라고 하고 N=남은 조각의 개수라고 하자.
- 이걸 이용해서 점화식세울것.
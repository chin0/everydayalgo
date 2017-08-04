# 풀이

## 접근 방식
입력의 크기가 크지않고, 1초정도로 시간도 넉넉히 준다. -> 완전 탐색

재귀 호출을 이용한 완전 탐색에서는 큰 문제를 작은 문제로 나누어 생각해야한다.

0. 서로 친구인지의 여부는 2차원 배열을 이용해 정보를 저장한다. friendList[i][j]가 true면, i와 j는 친구이다.
1. 함수는 인자로 false로 초기화된 배열을 받는다.(크기는 n만큼)
2. 2차원 배열을 순회하면서 친구를 찾는다. 그리고 인자로 넘겨받은 배열[i]와 배열[j]를 검사해서 이미 짝지어졌는지(true인지) 체크한다.
3. 찍지어지지 않았다면 i,j를 체크하고 재귀호출한다.
4. 모든 번호가 체크되었다면 true를 반환한다.
5. 이걸 받아서 더하면 된다.

```
int picnic(int n,bool check[10])
{
    bool fin = true;
    //모든 번호가 체크되었는지 확인.
    for(int i = 0; i < n; i++) {
        if(!check[i])
            fin = false;
    }
    //체크되어있다면 탈출
    if(fin) return true;

    int count = 0;
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            if(!check[i] && !check[j] && friendList[i][j]){
                check[i] = check[j] = true;
                count += picnic(n,check);
                check[i] = check[j] = false;
            }
        }
    }
    return count;
}
```

이 경우 문제점은 (1,2)(3,4)와 (3,4)(1,2)를 다르게 본다는것이다. (중복)

이런 문제점이 발생할때 가장 편한방법은 일단 답의 조건을 강제하는것이다.

이 경우에는 사전순으로 가장 작은 수를 먼저 샌다.

ex) (0,1)(2,3) -> O (2,3)(0,1) -> X

```
int picnic(int n,bool student[10])
{
    int firstFree = -1;
    for(int i = 0; i < n; i++) 
        if(!student[i]){
            firstFree = i;
            break;
        }
    if(firstFree == -1) return true;

    int count = 0;
    for(int i = firstFree+1; i < n; i++) {
        if(friendList[firstFree][i] && !student[i]) {
            student[i] = student[firstFree] = true;
            count += picnic(n,student);
            student[i] = student[firstFree] = false;
        }
    }
    return count;
}
```

## 결론
- 완전 탐색에서는 중복된 경우를 세는 경우가 많다. 
- 재귀 호출을 사용할때는 항상 큰 문제를 해결하는 과정을 작은문제로 나누는것이 중요하다.


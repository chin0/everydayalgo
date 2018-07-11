# 백준 1463

- 점화식은 매우 직관적으로 짤수 있었다.
  - 초기 상태:
    - dp[1] = 0
    - dp[2] = 1
    - dp[3] = 1
  - 점화식

```
dp[i] = 
	if i % 2 == 0 && i % 3 == 0: min(dp[i-1],dp[i/2],dp[i/3]) + 1
	if i % 3 == 0: min(dp[i/3],dp[i-1]) + 1
	if i % 2 == 0: min(dp[i/2], dp[i-1]) + 1
	else dp[i-1] + 1
```



- 처음엔 top-down방식으로 동적계획법을 적용시켰는데 어차피 중복된 계산이 없는데 내가 왜 이런 방법을 생각했는지 이해할수없다;
- 그래서 bottom-up방식으로 다시 작성했고, 시간복잡도는 대충 O(n)정도 나온다. 

```c
#include <iostream>
#include <algorithm>
#include <vector>


using namespace std;

int dp[1000001];

int solve(int n) {
    dp[0] = 0;
    dp[1] = 0;
    dp[2] = 1;
    dp[3] = 1;
    for(int i = 4; i <= n; i++) {
        dp[i] = dp[i-1];
        if(i % 3 == 0)
            dp[i] = min(dp[i],dp[i/3]);
        if(i % 2 == 0)
            dp[i] = min(dp[i],dp[i/2]);
        dp[i] += 1;
    }

    return dp[n];
}
int main(void) {
    int n;
    cin >> n;

    ios_base::sync_with_stdio(false);
    cout << solve(n) << endl;
}

```

나중에 다른 방법으로 더 빠르게 푸러봐야겠다.


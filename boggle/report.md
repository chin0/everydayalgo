# Boggle (난이도: 하,분류:완전탐색)

## 문제
![boggle](https://algospot.com/media/judge-attachments/09ee7a6e752f07b0d99b82a010938ab4/boggle.png)

- 5x5 크기의 알파벳 격자를 가지고 하는 게임.
- 상하좌우/대각선으로 인접한 칸들의 글자들을 이어서 단어를 찾아내는것.
- 위 그림에서 PRETTY,GIRL, REPEAT등의 단어를 (b,c,d)와 같이 찾을수 있음.
- 각 글자들은 대각선으로도 이어질수 있으며, 한글자가 두번 이상 사용될수도 있음.

- 요구사항: hasWord(y,x,word) -> 보글 체험판의 (y,x)에서 시작하는 단어 word의 존재 여부를 반환한다.

## 풀이.
- 완전 탐색이므로 재귀로 짜면 편리하다.
- 실패 조건은 x,y가 범위를 넘었을때, 현재 문자가 word[0]과 다를때.
- 성공 조건은 word[0]이 현재 문자와 같고 word.size()가 1일때(마지막 문자)
- 모든 경우의 이동할 x와 y의 경우를 배열에 넣어놓고 for문을 돌려서 재귀호출한다. 그리고 재귀 호출한 함수가 true를 반환하면 이 함수는 true를 반환한다.
- 항상 인자의 값을 바꿀일이 없으면 const 참조형으로 인자를 받자(쓸데없는 복사연산을 막고 의도치 않은 수정을 피할수있음.)
- 배열 범위 검사 함수도 따로 분리해주면 보기 편하다.

```
//grid [x][y] 또는 dx,dy로 분리해서 해도됨.
const int grid[8][2] = {{1,1},{1,-1},{1,0},{0,1},{0,-1},{-1,-1},{-1,0},{-1,1}}; 

bool hasWord(int x, int y, const string& word)
{
    if(!inRange(x,y))
        return false;
    if(word[0] != map[y][x])
        return false;
    if(word.size() == 1) return true;

    for(int direction = 0;direction< 8; direction++) {
        int nextY = y + grid[direction][1], nextX = x + grid[direction][0];
        if(hasWord(nextX,nextY,word.substr(1))) {
            return true;
        }
    }
    return false;
}
```

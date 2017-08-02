#include <iostream>
#include <string>
using namespace std;

char map[5][5];

bool inRange(int x,int y)
{
    return (x >= 0 && x < 5 && y <5 && y >= 0);
}

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

int main(void)
{
    int x,y;
    string word;
    cin >> word;
    cin >> x >> y;

    for(int i = 0; i < 5; i++){
        for(int j = 0; j < 5; j++)
            cin >> map[i][j];
    }

    cout << hasWord(x,y,word) << endl;
}

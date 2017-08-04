#include <iostream>
#include <cstring>
using namespace std;

const int blockSize = 2;
//[blocknum][y][x]
const int blocks[4][2][2] = { { {1,1},{1,0} }, { {1,1},{0,1} }, { {0, 1},{1,1} }, { {1, 0}, {1, 1} } };
const int dx[4] = {0,1,0,1};
const int dy[4] = {0,0,1,1};

int height,width;
int map[20][20];

int countBlocks(int x, int y, int blockCount, int map[20][20])
{
    if(y == height-1) return false;
    if(!blockCount) return true;
    int block = -1;
    for(int blockNum = 0; blockNum < 4; blockNum++) {
        for(int i = 0; i < 2; i++) {
            for(int j = 0; j < 2; j++) {
                if(blocks[blockNum][i][j] == 1 && map[y+i][x+j] == 1) continue;
            }
        }
        block = blockNum;
        break;
    }

    if(block == -1) return false;

    for(int i = 0; i < 2; i++) {
        for(int j = 0; j < 2; j++) {
            if(blocks[block][i][j] == 1 && map[y+i][x+j] == 0)
                map[y+i][x+j] = blocks[block][x+i][y+i];
        }
    }
    int ret = 0;
    if(x == width-2)
        ret += countBlocks(x,y+1,blockCount-1,map);
    else
        ret += countBlocks(x+1,y,blockCount-1,map);
    return ret;
}


int main(void)
{
    int dotCount = 0;
    cin >> height >> width;

    for(int i = 0; i < height; i++) {
        for(int j = 0; j < width; j++) {
            int temp;
            cin >> temp;
            if(!temp) dotCount++;
            map[i][j] = temp;
        }
    }
    cout << countBlocks(0,0,dotCount/3,map) << endl;
}

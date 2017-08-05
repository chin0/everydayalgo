#include <iostream>
#include <vector>
#include <cassert>
using namespace std;

const int blockSize = 2;
//[blocknum][dy][dx]
int block[4][3][2] = { 
    { {0,0},{1,0},{0,1} }, 
    { {0,0}, {0,1}, {1,1} }, 
    { {0,0},{1,0},{1,1}}, 
    { {0,0},{1,0},{1,-1}}
};

int height,width;

typedef vector<vector<int> > BoardType;

//set == -1 -> unset block
// set == 1 -> set block
int setBlock(BoardType& board,int y,int x, int blocknum, int set)
{
    bool ok = true;
    for(int i = 0; i < 3; i++) {
        const int nx = x + block[blocknum][i][1];
        const int ny = y + block[blocknum][i][0];
        if(ny < 0 || ny >= board.size() || nx < 0 ||
                nx >= board[0].size())
            ok = false;
        else if((board[ny][nx] += set) > 1)
            ok = false;
    }
    return ok;
}

int cover(BoardType& board) {
    int y = -1, x = -1;
    //왼쪽 위 빈 블록부터 탐색(답을 강제해서 중복을 줄임)
    for(int i = 0; i < board.size(); ++i) {
        for(int j = 0; j < board[i].size(); j++)
            if(board[i][j] == 0 ) {
                y = i;
                x= j;
                break;
            }
        if(y != -1) break;
    }
    if(y == -1) return 1;
    int ret = 0;
    for(int type = 0; type < 4; ++type) {
        if(setBlock(board,y,x,type,1))
            ret += cover(board);
        setBlock(board,y,x,type, -1);
    }
    return ret;
}

int main(void)
{
    int c = 0;
    int dot =0;
    cin >> c;
    for(int i = 0; i < 3; i++) {
        cin >> height >> width;
        assert(1 <= height && height <= 20);
        assert(1 <= width && width <= 20);
        vector<vector<int> > map(height,vector<int>(width,0));

        for(int i = 0; i < height; i++) {
            for(int j = 0; j < width; j++) {
                char temp;
                cin >> temp;
                if(temp == '#')
                    map[i][j] = 1;
                else{
                    dot += 1;
                }
            }
        }
        if(dot % 3 || dot == 0) cout << '0' << endl;
        else cout << cover(map) << endl;
    }
}

#include <iostream>
#include <vector>
#include <string>

using namespace std;

//x,y
const int coverData[4][3][2] = {
    {{0,0}, {1,0},{0,1}},
    {{0,0}, {1,0},{1,1}},
    {{0,0}, {0,1},{1,1}},
    {{0,0}, {0,1},{-1,1}}
};

bool set_cover(vector<vector<int>>& board, int type, int x, int y, 
    int val)
{
    bool success = true;

    for(int i = 0; i < 3; i++) {
        int dx = coverData[type][i][0] + x;
        int dy = coverData[type][i][1] + y;
        if(dx < 0 || dx >= board[0].size() || dy >= board.size() || dy < 0) {
            success = false;
        }
        else if((board[dy][dx] += val) > 1) {
            success = false;
        }
    }
    return success;
}

int solve(vector<vector<int>>& board) {
    int x = -1, y = -1;

    for(int i = 0; i < board.size(); i++) {
        for(int j = 0; j < board[0].size(); j++) {
            if(board[i][j] == 0) {
                x = j;
                y = i;
                break;
            }
        }
        if(y != -1) break;
    }

    if(y == -1) return 1;
    int ret = 0;
    for(int type = 0; type < 4; type++) {
        if(set_cover(board,type,x,y,1)) {
            ret += solve(board);
        }
        set_cover(board, type, x,y,-1);
    }
    return ret;
}

int main(void)
{
    int c;
    
    cin.sync_with_stdio(false);
    cin.tie(0);
    
    cin >> c;

    for(int p = 0; p < c; p++) {
        int h,w;
        vector<vector<int>> board;
        cin >> h >> w;
        for(int i = 0; i < h; i++) {
            string s;
            vector<int> temp;
            cin >> s;
            for(int j = 0; j < w; j++) {
                if(s[j] == '#') temp.push_back(1);
                if(s[j] == '.') temp.push_back(0);
            }
            board.push_back(temp);
        }
        cout << solve(board) << endl;
    }
}
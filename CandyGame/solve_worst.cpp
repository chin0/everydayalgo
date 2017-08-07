#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

enum direction {LEFT,RIGHT,UP,DOWN} ;
int dx[4] = {-1,1,0,0};
int dy[4] = {0,0,-1,1};

bool inRange(int x, int y, int n) {
    return (x >= 0 && x < n && y >= 0 && y < n);
}

void swap(vector<vector<char> > &board, int nx, int ny, int x, int y)
{
    char temp = board[ny][nx];
    board[ny][nx] = board[y][x];
    board[y][x] = temp;
}

int count(int x, int y,direction dir, int n, vector<vector<char> > board) {
    int nx = dx[dir] + x;
    int ny = dy[dir] + y;
    if(inRange(x,y,n)) {
        if(inRange(nx,ny,n)) {
            if(board[ny][nx] == board[y][x]) return false;
            swap(board,nx,ny,x,y);
        } else return false;
    } else return false;

    int maxCnt = 0;

    for(int i = 0; i < n-1; i++) {
        int col=1;
        int row=1;
        for(int j = 0; j < n-1; j++) {
            if(board[i][j+1] == board[i][j]) 
                row++;
            else {
                maxCnt = max(maxCnt,row);
                row = 1;
            }
            if(board[j+1][i] == board[j][i]){
                col++;
            } else {
                maxCnt = max(maxCnt,col);
                col = 1;
            }
        }
        maxCnt = max(maxCnt,row);
        maxCnt = max(maxCnt,col);
    }
    return maxCnt;
}

int solve(vector<vector<char> > board, int n)
{
    int maxCnt = 0;

    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            maxCnt = max(maxCnt,count(i,j,UP,n,board));
            maxCnt = max(maxCnt,count(i,j,DOWN,n,board));
            maxCnt = max(maxCnt,count(i,j,LEFT,n,board));
            maxCnt = max(maxCnt,count(i,j,RIGHT,n,board));
        }
    }

    return maxCnt;
}


int main(void)
{
    int n;

    cin >> n;
    vector<vector<char> > board(n,vector<char>(n));
    
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            char temp;
            cin >> temp;
            board[i][j] = temp;
        }
    }
    cout << solve(board,n)<< endl;
    cout << endl;
}

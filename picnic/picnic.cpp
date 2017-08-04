#include <iostream>
#include <cstring>
using namespace std;

bool friendList[10][10];

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

int main(void)
{
    int c,n,m;
    static bool student[10];

    cin >> c;
    for(int i = 0; i < c; i++){
        cin >> n >> m;
        for(int i = 0; i < m; i++) {
            int f1, f2;
            cin >> f1 >> f2;
            friendList[f1][f2] = true;
            friendList[f2][f1] = true;
        }
        cout << picnic(n,student) << endl;
        memset(friendList, 0, n * m);
    }
}

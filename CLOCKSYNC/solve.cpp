#include <iostream>
using namespace std;

int clocks[16];

int SwitchSize[10] = {3,4,4,5,5,4,3,5,5,5};
int Switch[10][5] = {
    {0,1,2},
    {3,7,9,11},
    {4,10,14,15},
    {0,4,5,6,7},
    {6,7,8,10,12},
    {0,2,14,15},
    {3,14,15},
    {4,5,7,14,15},
    {1,2,3,4,5},
    {3,4,5,9,13}
};

int main(void)
{
    for(int i = 0; i < 16; i++) {
        cin >> clocks[i];
        clocks[i] %= 12;
    }

    int switchnum;
    while(1) {

        cin >> switchnum;

        for(int i = 0; i < SwitchSize[switchnum]; i++) {
            clocks[Switch[switchnum][i]] += 3;
            clocks[Switch[switchnum][i]] %= 12;
        }

        for(int i = 0; i < 12; i++)
            cout << clocks[i] << ' ';
        cout << endl;
    }
}


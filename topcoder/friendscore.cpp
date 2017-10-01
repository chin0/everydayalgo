#include <vector>
#include <algorithm>
using namespace std;

class FriendScore {
public:
    int highestScore(vector <string> friends) {
        int m = 0;
        for(int i = 0; i < friends.size(); i++) {
            int curmax = 0;
            for(int j = 0; j < friends.size(); j++) {
                if(i == j)
                    continue;
                if(friends[i][j] == 'Y')
                    curmax++;
                else {
                    for(int k = 0; k < friends.size(); k++) {
                        if(friends[i][k] == 'Y' && friends[j][k] == 'Y') {
                            curmax++;
                        }
                    }
                }
            }
            m = max(curmax,m);
        }
        return m;
    }
};
            

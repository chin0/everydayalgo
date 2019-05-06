#include <cstdio>
#include <vector>

using namespace std;

int main(void) {
    int n, k;
    scanf("%d %d", &n, &k);
    vector<int> data;

    for(int i = 0; i < n; i++) {
        data.emplace_back(i+1);
    }

    int index = k-1;
    printf("<");
    for(int i = 0; i < n-1; i++) {
        printf("%d, ", data[index]);
        data.erase(data.begin() + index);
        index += k-1;
        index %= data.size();
    }
    printf("%d>\n", data[0]);

}
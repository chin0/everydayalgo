#include <iostream>
#include <vector>
#include <numeric>
#include <string>
#include <functional>
 
int main()
{
    std::vector<int> v{1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
 
    for(int i = 0; i < 10; i++) {
        int sum = std::accumulate(v.begin()+i, v.end(), 0);
 
        std::cout << "sum: " << sum << '\n';
    }
}

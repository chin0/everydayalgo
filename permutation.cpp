#include <vector>
#include <iostream>

using namespace std;

int n = 5;
vector<int> permutation;
bool chosen[5];

void search() {
  if(permutation.size() == n) {
    for(auto i : permutation)
      cout << i << " ";
    cout << endl;
  } else {
    for(int i = 1; i <=n; i++) {
      if(chosen[i]) continue;
      chosen[i] = true;
      permutation.push_back(i);
      search();
      chosen[i] = false;
      permutation.pop_back();
    }
  }
}

int main(void)
{
  search();
}

#include <vector>
#include <iostream>

using namespace std;

int n = 5;

vector<int> subset;
void search(int k) {
	if(k == n+1) {
		for(auto i : subset) 
			cout << i << " ";
		cout << endl;
	} else {
		subset.push_back(k);
		search(k+1);
		subset.pop_back();
		search(k+1);
	}
}

int main(void)
{
	search(1);
}


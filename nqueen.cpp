#include <iostream>
#include <vector>


int n = 8;
int count = 0;
int col[100],diag1[100], diag2[100];

void search(int y) {
	if(y == n) {
		count++;
		return;
	}
	for(int x = 0; x < n; x++) {
		if(col[x] || diag1[x+y] || diag2[x-y+n-1]) continue;
		col[x] = diag1[x+y] = diag2[x-y+n-1] = 1;
		search(y+1);
		col[x]= diag1[x+y] = diag2[x-y+n-1] = 0;
	}
}

int main(void)
{
	search(0);
	std::cout << count; 
}


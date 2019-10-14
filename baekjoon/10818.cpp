#include <algorithm>
#include <cstdio>

using namespace std;

int main(void)
{
	int max=-10000001;
	int min=1000001;

	int n;
	scanf("%d", &n);
	for(int i = 0; i < n; i++) {
		int temp;
		scanf("%d", &temp);
		if(max < temp) max = temp;
		if(min > temp) min = temp;
	}
	printf("%d %d\n", min,max);
}
		



#include <cstdio>
#include <algorithm>

using namespace std;

int main(void)
{
	int arr[9];

	for(int i = 0; i < 9; i++) 
		scanf("%d", &arr[i]);

	int *max = max_element(arr,arr+9);
	printf("%d\n%d\n",*max,distance(arr,max)+1);
}

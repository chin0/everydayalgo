//EW있는거 개수 세주면 댐.
// 계속 순환할거니까.
#include <string>
#include <iostream>

using namespace std;

int main(void)
{
	int cns = 0,temp;
	string s;
	ios::sync_with_stdio(false);

	cin >> temp;
	cin >> s;

	for(auto i = s.begin(); i != s.end(); i++) {
		if( *i == 'E' && *(i+1) == 'W') {
			cns++;
		}
	}
	cout << cns << endl;
}


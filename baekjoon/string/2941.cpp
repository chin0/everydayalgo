//ㅋㅋㅋ
#include <string>
#include <iostream>

using namespace std;

int main()
{
	int cnt = 0;
	string s;
	cin >> s;

	for(int i = 0; i < s.length(); i++) {
		if(s[i] == 'c' && (s[i+1] == '=' || s[i+1] == '-')) i++;
		if(s[i] == 'l' || s[i] == 'n') {
			if(s[i+1] == 'j') i++;
		}
		if(s[i] == 's' || s[i] == 'z') {
			if(s[i+1] == '=') i++;
		}
		if(s[i] == 'd') {
			if(s[i+1] == 'z' && s[i+2] == '=') 
				i += 2;
			else if (s[i+1] == '-')
				i++;
		}
		cnt++;
	}
	cout << cnt << endl;
}




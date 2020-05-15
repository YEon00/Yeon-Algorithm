#include <iostream>
#include <string>
using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	string s; cin >> s;
	string answer;
	int length;
	if (s[0] < 4) {
		length = s.length() - 1;
		for (int i = 0; i < length; i++) {
			answer += "7";
		}
		
	}
	cout << answer << '\n';
	
	return 0;
}
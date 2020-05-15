#include <iostream>
#include <sstream>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	int num; int res = 0; int a = 0;
	int up = 0; bool check = false;
	bool first = true;
	string str; cin >> str;
	stringstream ss(str);
	while (ss >> num)
	{
		if (first && !check) res += num;
		char op;
		op = ss.get();
		if (op == '-') {
			if (a == 0) {
				if (first) {
					first = false;
					continue;
				}
				res -= num;
				continue;
			}
			if (check) {
				up += num;
				res += up * (-1);
				check = false;
				up = 0;
			}
			check = true;
			up = 0; a = 0;
			continue;
		}
		else {
			up += num;
			a++;
		}
	}
	if (up > 0)
		res += up * (-1);
	cout << res;
}
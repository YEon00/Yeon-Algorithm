#include <iostream>
#include <string>
#include <vector>

using namespace std;
vector <int> v, v1;
vector <char> res;
int n;

void bin(int x) {
	while (x != 0) {
		if (x % 2 == 1) {
			res.push_back('#');
		}
		else
			res.push_back(' ');
		x /= 2;
	}
	if (res.size() < n) {
		while (res.size() < n) {
			res.push_back(' ');
		}
	}
	reverse(res.begin(), res.end());

}

int main() {
	cin >> n;
	for (int i = 0; i < n; i++) {
		int a; cin >> a;
		v.push_back(a);
	}
	for (int i = 0; i < n; i++) {
		int a; cin >> a;
		v1.push_back(a);
	}
	for (int i = 0; i < n; i++) {
		int x = v[i] | v1[i];
		bin(x);
		for (int j = 0; j < n; j++) {
			cout << res[j];
		}cout << '\n';
		res.resize(0);
		
	}

}

#include <map>
#include <string>
#include <iostream>

using namespace std;

map<string, int> m1;
map<string, string> m2;
int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	int n, m;
	cin >> n >> m;
	for (int i = 1; i <= n; i++) {
		string s; cin >> s;
		m1[s] = i;
		m2[to_string(i)] = s;
	}
	for (int i = 0; i < m; i++) {
		string s; cin >> s;
		if (m1.count(s)) {
			cout << m1[s] << '\n';
		}
		else if (m2.count(s)) {
			cout << m2[s] << '\n';
		}
	}

}
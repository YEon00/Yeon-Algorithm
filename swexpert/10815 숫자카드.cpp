#include <iostream>
#include <vector>
#include <set>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	int n, m;
	set <int> s;
	vector <int> v;
	cin >> n;
	for (int i = 0; i < n; i++) {
		int x; cin >> x;
		s.insert(x);
	}
	cin >> m;
	for (int i = 0; i < m; i++) {
		int x; cin >> x;
		v.push_back(s.count(x));
	}
	for (int i = 0; i < v.size(); i++) {
		cout << v[i] << ' ' ;
	}
	cout << '\n';

}
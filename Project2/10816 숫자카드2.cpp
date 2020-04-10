#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
	int n, m;
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	vector <int> v;
	cin >> n;
	for (int i = 0; i < n; i++) {
		int x; cin >> x;
		v.push_back(x);
	}
	sort(v.begin(), v.end());
	cin >> m;
	for (int i = 0; i < m; i++) {
		int x; cin >> x;
		cout << upper_bound(v.begin(), v.end(), x) - 
			lower_bound(v.begin(), v.end(), x) << " ";
	}
	cout << '\n';
	return 0;
}

#include <iostream>
#include <set>
using namespace std;

int main() {
	int n, m;
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	multiset<int> s;
	cin >> n;
	for (int i = 0; i < n; i++) {
		int x; cin >> x;
		s.insert(x);
	}
	cin >> m;
	for (int i = 0; i < m; i++) {
		int x; cin >> x;
		cout << s.count(x) <<' ';
	}

	printf("\n");

	return 0;
}
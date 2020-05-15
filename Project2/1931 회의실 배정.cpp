#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

bool cmp(pair<int, int> a, pair<int, int> b) {
	if (a.second == b.second) {
		return a.first < b.first;
	}
	else {
		return a.second < b.second;
	}
}


int main() {
	int n; cin >> n;
	vector <pair<int, int>> v;
	for (int i = 0; i < n; i++) {
		int x, y; cin >> x >> y;
		v.push_back({ x, y });
	}
	sort(v.begin(), v.end(), cmp);
	int idx = 0;
	int ans = 0;
	for (int i = 0; i < v.size(); i++) {
		if (idx <= v[i].first) {
			idx = v[i].second;
			ans += 1;
		}
	}
	cout << ans << '\n';


}
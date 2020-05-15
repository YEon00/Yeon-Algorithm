#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

bool cmp(pair<int, string> a, pair<int, string> b) {
	return a.first < b.first;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	vector <pair<int, string>> v;
	int n; cin >> n;
	for (int i = 0; i < n; i++) {
		int x; string s; 
		cin >> x >> s;
		v.push_back({ x,s });
	}
	stable_sort(v.begin(), v.end(),cmp);
	for (int i = 0; i < v.size(); i++) {
		cout << v[i].first << " " << v[i].second << '\n';
	}
}
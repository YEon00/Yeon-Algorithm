#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

bool cmp(pair<int, int> a, pair<int, int> b) {
	return a.first < b.first;
}

int main() {
	int n; cin >> n;
	vector <pair<int, int>> v;
	for (int i = 0; i < n; i++) {
		int time1, time2;
		cin >> time1 >> time2;
		v.push_back({ time1,time2 });
	}
	sort(v.begin(), v.end(), cmp);
	int cnt = 1;
	for (int i = 0; i < n; i++) {
		for (int j = i + 1; j < n; j++) {
			if (v[j].first < v[i].second)
				cnt++;
		}
	}
	cout << cnt;
}
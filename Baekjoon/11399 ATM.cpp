#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
	int n; cin >> n;
	vector <int> v(n);
	for (int i = 0; i < n; i++) {
		cin >> v[i];
	}
	sort(v.begin(), v.end());
	int sum = v[0];
	int ans = v[0];
	for (int i = 1; i < n; i++) {
		sum += v[i];
		ans += sum;
	}
	cout << ans << '\n';
}
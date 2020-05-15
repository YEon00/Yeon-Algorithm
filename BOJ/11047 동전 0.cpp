#include <iostream>
#include <vector>
using namespace std;

int main() {
	int n, k; cin >> n >> k;
	int ans = 0;
	vector <int> v(n);
	for (int i = 0; i < n; i++) {
		cin >> v[i];
	}
	for (int i = n - 1; i >= 0; i--) {
		ans += k / v[i];
		k %= v[i];
	}
	cout << ans << "\n";
	return 0;

}
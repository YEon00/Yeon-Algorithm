#include <iostream>
using namespace std;

long long a[1000001];
long long result = 0;
long long mid, bar;
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	long long left = 1, right = 0;
	long long n, m; cin >> n >> m;
	for (int i = 0; i < n; i++) {
		cin >> a[i];
		if (right < a[i]) right = a[i];
	}
	while (left <= right) {
		bar = 0;
		mid = (left + right) / 2;
		for (int i = 0; i < n; i++) {
			if (a[i] > mid)
				bar += a[i] - mid;
		}
		if (bar >= m) {
			if (result < mid)
				result = mid;
			left = mid + 1;
		}
		else right = mid -1;
	}
	cout << result;
}
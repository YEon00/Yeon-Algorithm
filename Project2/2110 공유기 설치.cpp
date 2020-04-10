#include <iostream>
#include <algorithm>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	int n, c; cin >> n >> c;
	int a[200001];
	int left = 1,right = 0;
	int cnt, res, mid;
	int d = 0;
	for (int i = 0; i < n; i++) {
		cin >> a[i];
	}
	sort(a, a + n);
	right = a[n];
	while (left <=right)
	{
		cnt = 1;
		mid = (left + right) / 2;
		int start = a[0];
		for (int i = 1; i < n; i++) {
			d = a[i] - start;
			if (mid <= d) {
				cnt++;
				start = a[i];
			}
		}
		if (cnt >= c) {
			res = mid;
			left = mid + 1;
		}
		else
			right = mid - 1;
	}
	cout << res << '\n';
}
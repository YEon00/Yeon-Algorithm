#include <iostream>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	long long k, n;
	long long left = 1, right = 0, mid;
	long long result = 0;
	long long a[10001];
	cin >> k >> n;
	for (int i = 0; i < k; i++) {
		cin >> a[i];
		if (a[i] > right) right = a[i]; //제일 큰값 오른쪽
	}
	while (left <= right) {
		long long temp = 0;
		mid = (left + right) / 2;
		for (int i = 0; i < k; i++) {
			temp += a[i] / mid;
		}
		if (temp >= n) {
			result = mid;
			left = mid + 1;
		}
		else {
			right = mid - 1;
		}
	}
	cout << result << '\n';

}
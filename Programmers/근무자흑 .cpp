#include <iostream>
#include <algorithm>

using namespace std;
int main() {
	int input[100001];
	int n, k; cin >> n >> k;
	for (int i = 0; i < n; i++) {
		cin >> input[i];
	}
	int res;
	if (n <= k)
		res = 1;
	else {
		n -= k; k--;
		if (n % k == 0)
			res = n / k + 1;
		else
			res = n / k + 2;
	}
	cout << res << '\n';
}
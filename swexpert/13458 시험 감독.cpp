#include <iostream>
using namespace std;

long long n; long long a[1000001];
long long b, c; long long cnt = 0;

long long exam(long long x, long long y) {
	for (long long i = 0; i < n; i++) {
		a[i] -= b; cnt++;
		if (a[i] <= 0)
			continue;
		if (a[i] % c != 0)
			cnt += a[i] / c + 1;
		else
			cnt += a[i] / c;
	}
	return cnt;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	cin >> n;
	for (long long i = 0; i < n; i++) {
		cin >> a[i];
	}
	cin >> b >> c;
	cout << exam(b, c) << '\n';
}
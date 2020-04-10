#include <iostream>
using namespace std;

int dp[100001];

int main() {
	int n; cin >> n;
	dp[1] = 3;
	dp[2] = 7;
	for (int i = 3; i <= n; i++) {
		dp[i] =( 2 * dp[i - 1] + dp[i - 2]) % 9901;
	}
	cout << dp[n] << '\n';
}
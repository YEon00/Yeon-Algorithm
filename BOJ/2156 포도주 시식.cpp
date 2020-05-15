#include <iostream>
#include <algorithm>
using namespace std;
int dp[10001]; int memo[10001];
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	
	int n; cin >> n;
	for (int i = 1; i <= n; i++) {
		cin >> memo[i];
	}
	dp[0] = 0; dp[1] = memo[1];
	dp[2] = memo[1] + memo[2];

	for (int i = 3; i <= n; i++) {
		dp[i] = max(max(dp[i - 1], dp[i - 2] + memo[i]), dp[i - 3] + memo[i - 1] + memo[i]);
	}

	cout << dp[n] << '\n';

}
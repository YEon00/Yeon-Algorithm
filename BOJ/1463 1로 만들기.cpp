#include <iostream>
#include <algorithm>
using namespace std;

int dp[1000001];

int main() {
	dp[0] = 0; dp[1] = 0; 
	dp[2] = 1; dp[3] = 1;
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int n; cin >> n;
	for (int i = 4; i <= n; i++) {
		dp[i] = dp[i - 1] + 1;
		if (i % 2 == 0 && dp[i] > dp[i / 2] + 1) {
			dp[i] = dp[i / 2] + 1;
		}
		if (i % 3 == 0 && dp[i] > dp[i / 3] + 1) {
			dp[i] = dp[i / 3] + 1;
		}
	}
	cout << dp[n] << '\n';
}
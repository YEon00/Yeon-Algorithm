#include <iostream>
using namespace std;

int n; int res = 0;
int col[15];

bool pos(int k) {
	for (int i = 0; i < k; i++) {
		if (col[i] == col[k])
			return false;
		if (abs(col[k] - col[i]) == k - i)
			return false;
	}
	return true;
}

void dfs(int k) {
	if (k == n) {
		res++; return;
	}
	for (int i = 0; i < n; i++) {
		col[k] = i;
		if (pos(k))
			dfs(k + 1);
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	cin >> n;
	dfs(0);
	cout << res;
}


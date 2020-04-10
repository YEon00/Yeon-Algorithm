#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int main() {
	int n, k; cin >> n >> k;
	vector <int> v;
	for (int i = 0; i < n; i++) {
		int x; cin >> x;
		v.push_back(x);
	}
	sort(v.begin(), v.end());
	
	for (int i = 1; i < k; i++) {
		 next_permutation(v.begin(), v.end());
	}
	for (auto x : v) {
		cout << x;
	}

}
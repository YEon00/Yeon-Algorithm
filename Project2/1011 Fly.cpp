#include <iostream>
using namespace std;

int main() {
	int t; cin >> t;
	while (t--) {
		int a = 1; int res = 0;
		int x, y; cin >> x >> y;
		int num = y - x + 1; int cnt = 1;
		if (num % 2 != 0) {
			while (cnt <= num / 2) {
				cnt += a;
				a++; res++;
			}
			res = res * 2 + 2;
		}
		else {
			while (cnt <= num / 2) {
				cnt += a;
				a++; res++;
			}
			res = res * 2 + 1;
		}
		cout << res << '\n';
	}
}
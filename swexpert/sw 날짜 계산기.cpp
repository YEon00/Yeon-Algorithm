#include <iostream>
using namespace std;

int main() {
	int t, days[13]{ 0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };
	int month[2], day[2];
	cin >> t;
	for (int i = 1; i <= t; i++) {
		cin >> month[0] >> day[0] >> month[1] >> day[1];
		int result = 0;
		for (int k = month[0]; k < month[1]; k++) {
			result += days[k];
		}
		result += day[1] - (day[0] - 1);
		cout << "#" << i << ' ' << result << '\n';
	}
}
#include <iostream>
using namespace std;

int main() {
	int max = -1;
	int d, u;
	int cnt = 0;
	for (int i = 0; i < 4; i++) {
		cin >> d >> u; //³»¸°, Åº»ç¶÷
		cnt = cnt - d + u;
		if (max < cnt)
			max = cnt;
	}
	cout << max << '\n';
}
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
	int a[10];
	int cnt = 0;
	for (int i = 0; i < 9; i++) {
		cin >> a[i];
		cnt += a[i];
	}
	cnt -= 100;
	for (int i = 0; i < 10; i++) {
		int b = 1;
		for (int j = i + 1; j < 10; j++) {
			if (a[i] + a[j] == cnt)
			{
				a[i] = 100;
				a[j] = 100;
				b = 0;
				break;
			}
			
		}
		if (b == 0)
			break;
	}
	sort(a, a + 9);
	for (int i = 0; i < 7; i++) {
		cout << a[i]<<'\n';
	}
}
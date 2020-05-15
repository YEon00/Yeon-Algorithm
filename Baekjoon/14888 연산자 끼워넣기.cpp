#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
	int n;	cin >> n;
	int temp, value;
	int num[11];
	int max = -1000000000, min = 1000000000;
	vector <int> op; 
	for (int i = 0; i < n; i++)
		cin >> num[i];
	for (int i = 0; i < 4; i++) {
		cin >> temp;
		for (int j = 0; j < temp; j++)
			op.push_back(i);
	}
	do {
		value = num[0];
		for (int m = 0; m < op.size(); m++) {
			if (op[m] == 0)
				value += num[m + 1];
			else if (op[m] == 1)
				value -= num[m + 1];
			else if (op[m] == 2)
				value *= num[m + 1];
			else
				value /= num[m + 1];
		}
		if (value > max)
			max = value;
		if (value < min)
			min = value;
	} while (next_permutation(op.begin(), op.end()));
	cout << max << "\n" << min;

}
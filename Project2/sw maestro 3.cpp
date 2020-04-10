#include <iostream>
#include <deque>

using namespace std;
int main() {
	int n, k;
	int answer = 0;
	int arr[3001];
	deque <int> dq;
	cin >> n >> k;
	for (int i = 0; i < n; i++) {
		cin >> arr[i];
	}
	for (int i = 0; i < n - 1; i++) {
		int res = arr[i + 1] - arr[i];
		dq.push_back(res);
	}
	while (k-- != 1) {
		int first = dq.front();
		int end = dq.back();
		if (first > end) {
			dq.pop_front();
		}
		else
		{
			dq.pop_back();
		}
		
	}

	if (k == 1) {
		answer = 0;
	}
	else
	{
		while (!dq.empty()) {
			answer += dq.front();
			dq.pop_front();
		}
	}


	cout << answer;

}

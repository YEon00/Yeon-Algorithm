#include <iostream>
#include <queue>
using namespace std;

int main() {
	int n, consumer;
	int a[10]; int time = 0;
	cin >> n >> consumer;
	queue <int> q;
	for (int i = 0; i < n; i++) {
		int x; cin >> x;
		q.push(x);
	}
	for (int i = 0; i < consumer; i++) {
		a[i] = q.front();
		q.pop();
	}
	while (!q.empty()) {
		for (int i = 0; i < consumer; i++) {
			a[i]--;
			if (a[i] == 0) {
				a[i] = q.front();
				q.pop();
			}
		}
		time++;
	}
	int maxm=0;
	for (int i = 0; i < consumer; i++) {
		maxm = maxm < a[i] ? a[i] : maxm;
	}
	time += maxm;

	cout << time << '\n';
}
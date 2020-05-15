#include <iostream>
#include <queue>

using namespace std;

priority_queue <int> pq;
queue <pair<int, int>> q;

int main() {
	int test; cin >> test;
	while (test--) {
		int n, m; cin >> n >> m;
		for (int i = 0; i < n; i++) {
			int x; cin >> x;
			q.push({ x,i });
			pq.push(x);
		}
		int time = 0;
		while (!q.empty()) {
			int front = q.front().first;
			int second = q.front().second;
			if (pq.top() == q.front().first) {
				time++;
				if (q.front().second == m)
					break;
				else {
					q.pop();
					pq.pop();
				}
			}
			else {
				q.push({ front,second });
				q.pop();
			}
		}
		cout << time << '\n';
	}

}


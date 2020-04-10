#include <iostream>
#include <deque>
using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	int n; cin >> n;
	deque <int> dq;
	deque <int> answer;
	for (int i = 1; i <= n; i++) {
		dq.push_back(i);
	}
	while (dq.size()> 1) {
		answer.push_back(dq.front());
		dq.pop_front();
		dq.push_back(dq.front());
		dq.pop_front();
	}
	for (int i = 0; i < answer.size(); i++) {
		cout << answer.at(i)<<' ';
	}
	cout << dq.at(0) << '\n';

	return 0;
}
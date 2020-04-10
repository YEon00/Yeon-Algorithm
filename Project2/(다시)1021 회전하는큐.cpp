#include <iostream>
#include <deque>
#include <algorithm>
using namespace std;
int n, m, check;
deque <int> dq; deque <int> num;
int cnt = 0;

void left(int x) {
	for (int i = 0; i < dq.size(); i++) {
		if (num[x] == dq.front()) {
			dq.pop_front();
			break;
		}
		else {
			dq.push_back(dq.front());
			dq.pop_front();
			cnt++;
		}
	}
}

void right(int x) {
	for (int i = 0; i < dq.size(); i++) {
		if (num[x] == dq.front()) {
			dq.pop_front();
			break;
		}
		else {
			dq.push_front(dq.back());
			dq.pop_back();
			cnt++;
		}
	}
}


int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	cin >> n >> m;
	for (int i = 1; i <= n; i++) {
		dq.push_back(i);
	}
	for (int i = 0; i < m; i++) {
		int a; cin >> a;
		num.push_back(a);
	}
	for (int i = 0; i < m; i++) {
		int check = 1;
		for (deque<int>::iterator iter = dq.begin(); iter != dq.end(); iter++)
		{
			if (*iter == num[i])
				break;
			check++;
		}
		int le = check - 1;
		int rig = dq.size() - check + 1;
		if (le < rig) 
			left(i);
		else right(i);
	}

	cout << cnt << '\n';

	return 0;
}
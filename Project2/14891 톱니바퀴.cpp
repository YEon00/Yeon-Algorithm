#include <iostream>
#include <deque>
using namespace std;
deque <int> gear[4];
void turn(int x,int direct) {
	if (direct == 1) {
		gear[x].push_front(gear[x].back());
		gear[x].pop_back();
	}else if (direct == -1) {
		gear[x].push_back(gear[x].front());
		gear[x].pop_front();
	}
}
void comp(int x,int direct) {
	
}

int main() {
	deque <int> gear[4];
	for (int i = 0; i < 4; i++) {
		for (int j = 0; j < 8; j++) {
			int a; cin >> a;
			gear[i].push_back(a);
		}
	}
	int n; cin >> n;
	for (int i = 0; i < n; i++) {
		int wh, d; cin >> wh >> d;
		switch (wh)
		{
		case 1:

		case 2:
		case 3:
		case 4:
		default:
			break;
		}
	}
	
}
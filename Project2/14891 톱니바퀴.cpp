#include <iostream>
#include <deque>
using namespace std;
deque <int> gear[5];
int r[5] = { 0 };
void turn(int x, int direct) {
	if (direct == 0) {
		return;
	}
	else if (direct == 1) {

		gear[x].push_front(gear[x].back());
		gear[x].pop_back();

	}
	else if (direct == -1) {

		gear[x].push_back(gear[x].front());
		gear[x].pop_front();

	}
}
void right(int x, int y) {
	while (x + 1 < 5) {
		if (gear[x][2] != gear[x + 1][6]) {
			switch (y)
			{
			case 1: r[x + 1] = -1;
				break;
			case -1: r[x + 1] = 1;
				break;
			default:
				break;
			}
		}
		y = r[x + 1]; x++;
	}
}
void left(int x, int y) {
	while (x - 1 > 0) {
		if (gear[x - 1][2] != gear[x][6]) {
			switch (y)
			{
			case 1: r[x - 1] = -1;
				break;
			case -1: r[x - 1] = 1;
				break;
			default:
				break;
			}
		}
		y = r[x - 1]; x--;
	}
}

int main() {
	for (int i = 1; i < 5; i++) {
		for (int j = 0; j < 8; j++) {
			char a; cin >> a;
			gear[i].push_back(a - 48);
		}
	}
	int n; cin >> n;
	for (int i = 0; i < n; i++) {
		int wh, d; cin >> wh >> d;
		r[wh] = d;
		right(wh, d);
		left(wh, d);
		for (int i = 1; i < 5; i++) {
			turn(i, r[i]);
		}
		for (int i = 0; i < 5; i++) {
			r[i] = 0;
		}
	}
	int res = 0;
	for (int i = 1; i < 5; i++) {
		if (i == 1) {
			if (gear[i][0] == 1)
				res += 1;
		}
		else if (i == 2) {
			if (gear[i][0] == 1)
				res += 2;
		} 
		else if (i == 3) {
			if (gear[i][0] == 1)
				res += 4;
		}
		else if (i == 4) {
			if (gear[i][0] == 1)
				res += 8;
		}
	}
	cout << res;

}
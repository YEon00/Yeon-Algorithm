#include <iostream>
using namespace std;

int map[101][101];
int n, L; int cnt = 0;
int down, up; int check = 1;

void load1(int x, int y) {
	int pre = map[x][y]; down = L; check = 1;
	for (int i = 1; i < n; i++) {
		if (abs(pre - map[x][i]) > 1)
			return;
		if (pre == map[x][i]) {

			if (down == L) // 숫자같으면 길이 체크
				check++;
			else if (down < L) { // 내려가는 도중
				down--;
				if (down == 0)
					down = L + 1;
			}
			else if (down > L) {
				down--;
				if (check == 0)
					check++;
			}
		}
		else {
			if (down < L)
				return;
			if (pre - map[x][i] > 0) //내리막길
			{
				check = 0;
				pre = map[x][i];
				if (down > L)
					down--;
				down--;
				if (down == 0)
					down = L + 1;
			}
			else { //오르막길
				pre = map[x][i];
				if (check >= L)
					check = 1;
				else
					return;
			}
		}
	}
	if (down < L)
		return;
	cnt++;
}

void load(int x, int y) {
	int pre = map[x][y]; down = L; check = 1;
	for (int i = 1; i < n; i++) {
		if (abs(pre - map[i][y]) > 1)
			return;
		if (pre == map[i][y]) {

			if (down == L) // 숫자같으면 길이 체크
				check++;
			else if (down < L) { // 내려가는 도중
				down--;
				if (down == 0)
					down = L + 1;
			}
			else if (down > L) {
				down--;
				if (check == 0)
					check++;
			}
		}
		else {
			if (down < L)
				return;
			if (pre - map[i][y] > 0) //내리막길
			{
				check = 0;
				pre = map[i][y];
				if (down > L)
					down--;
				down--;
				if (down == 0)
					down = L + 1;
			}
			else { //오르막길
				pre = map[i][y];
				if (check >= L)
					check = 1;
				else
					return;
			}
		}

	}
	if (down < L)
		return;
	cnt++;
}

int main() {
	int test; cin >> test;
	for (int t = 1; t <= test; t++) {
		cin >> n >> L;
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				cin >> map[i][j];
			}
		}
		for (int i = 0; i < n; i++) { //열만 확인
			load(0, i);
		}

		for (int i = 0; i < n; i++) { //열만 확인
			load1(i, 0);
		}
		cout << "#" << t << " " << cnt << '\n';
	}
}
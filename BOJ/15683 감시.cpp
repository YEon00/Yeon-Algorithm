#include <iostream>
using namespace std;

int n, m;
int non = 0; int min_cctv = 64;

int dx[4] = { -1,0,1,0 };
int dy[4] = { 0,1,0,-1 };

int map[9][9];

void cctv(int x, int y, int num) {
	switch (num)
	{
	default:
		break;
	}
}

int main() {
	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> map[i][j];
		}
	}
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (map[i][j] > 0 && map[i][j] != 6)
				cctv(i, j, map[i][j]);
		}
	}
}
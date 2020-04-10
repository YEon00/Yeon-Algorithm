#include <iostream>
using namespace std;

int dx[] = { 0,1,0,-1 };
int dy[] = { -1,0,1,0 };
int check[51][51]; int map[51][51];
int cnt = 0;
int n, m, d, r, c;
int res = 0;
bool b;

void clean(int x, int y, int direct) {
	if (map[x][y] == 1) {
		return;
	}
	else if (check[x][y] == 0)
	{
		res++; check[x][y] = 1;
	}
	int temp = direct;
	if (direct != 0)
		direct = 4 - direct;
	int cnt = 0;
	for (int i = direct; cnt < 4; i++, cnt++) {
		if (temp > 0)temp -= 1;
		else temp = 3;
		if (i >= 4) i = 0;
		int nx = x + dx[i]; int ny = y + dy[i];
		if (nx >= 0 && ny >= 0 && nx < n && ny < m) {
			if (check[nx][ny] == 0 && map[nx][ny] != 1) {
				clean(nx, ny, temp);
				return;
			}

		}
	}
	switch (temp)
	{
	case 0: clean(x + 1, y, temp); break;
	case 1: clean(x, y - 1, temp); break;
	case 2: clean(x - 1, y, temp); break;
	case 3: clean(x, y + 1, temp); break;
	default:
		break;
	}

}
int main() {
	cin >> n >> m;
	cin >> r >> c >> d;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> map[i][j];
		}
	}
	clean(r, c, d);
	cout << res << '\n';

}
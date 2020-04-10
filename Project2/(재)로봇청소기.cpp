#include <iostream>
using namespace std;

int map[51][51];
int N, M;
int r, c, d;
int cnt = 0;

int dx[] = { -1,0,1,0 };
int dy[] = { 0,1,0,-1 };

int Turn_Direction(int d)
{
	if (d == 0) return 3;
	else if (d == 1) return 0;
	else if (d == 2) return 1;
	else if (d == 3) return 2;
}

void clean(int x, int y, int direct) {
	int d = direct;
	if (map[x][y] == 0)
	{
		cnt++; map[x][y] = 2;
	}
	for (int i = 0; i < 4; i++) {
		int nd = Turn_Direction(d);
		int nx = x + dx[nd]; int ny = y + dy[nd];
		if (map[nx][ny] == 0) {
			clean(nx, ny, nd);
			return;
		}
		d = nd;
	}
	switch (direct)
	{
	case 0: x += 1; break;
	case 1: y -= 1; break;
	case 2: x -= 1; break;
	case 3: y += 1; break;
	default:
		break;
	}
	if (map[x][y] == 1) {
		return;
	}
	clean(x, y, direct);
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	cin >> N >> M;
	cin >> r >> c >> d;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			cin >> map[i][j];
		}
	}
	clean(r, c, d);
	cout << cnt << '\n';
}
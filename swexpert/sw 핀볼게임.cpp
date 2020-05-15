#include <vector>
#include <iostream>

using namespace std;
int n; int cnt = 0; int max_cnt = -1;
int nx, ny, nd; bool first = true;
int map[101][101];

vector <pair<int, int>> warm[11];

int dx[] = { -1,0,1,0 };
int dy[] = { 0,1,0,-1 };

int direct(int shape, int d) {
	int new_direct;
	switch (shape)
	{
	case 1:
		if (d == 0) new_direct = 2;
		else if (d == 1) new_direct = 3;
		else if (d == 2) new_direct = 1;
		else if (d == 3) new_direct = 0;
		break;
	case 2:
		if (d == 0) new_direct = 1;
		else if (d == 1) new_direct = 3;
		else if (d == 2) new_direct = 0;
		else if (d == 3) new_direct = 2;
		break;
	case 3:
		if (d == 0) new_direct = 3;
		else if (d == 1) new_direct = 2;
		else if (d == 2) new_direct = 0;
		else if (d == 3) new_direct = 1;
		break;
	case 4:
		if (d == 0) new_direct = 2;
		else if (d == 1) new_direct = 0;
		else if (d == 2) new_direct = 3;
		else if (d == 3) new_direct = 1;
		break;
	case 5:
		if (d == 0) new_direct = 2;
		if (d == 1) new_direct = 3;
		if (d == 2) new_direct = 0;
		if (d == 3) new_direct = 1;
		break;

	default:
		break;
	}
	return new_direct;
	
}

int wall(int d) {
	if (d == 0) d = 2;
	else if (d == 1) d = 3;
	else if (d == 2) d = 0;
	else if (d == 3) d = 1;
	return d;
}

void warmhall(int x, int y) {
	if (x == warm[map[x][y]][0].first) {
		if (y == warm[map[x][y]][0].second) {
			nx = warm[map[x][y]][1].first;
			ny = warm[map[x][y]][1].second;
		}
		else {
			nx = warm[map[x][y]][0].first;
			ny = warm[map[x][y]][0].second;
		}
	}
	else {
		nx = warm[map[x][y]][0].first;
		ny = warm[map[x][y]][0].second;
	}
}

void pinball(int x, int y, int d) {
	if (!first && map[x][y] == -2)
		return;
	if (map[x][y] == -1)
		return;
	first = false;
	if (x < 0 || x >= n || y < 0 || y >= n) {
		cnt++;
		nd = wall(d);
		nx = x + dx[nd]; ny = y + dy[nd];
		pinball(nx, ny, nd);
		
	}
	else {
		if (map[x][y] > 0 && map[x][y] <= 5) {
			cnt++;
			nd = direct(map[x][y], d);
			nx = x + dx[nd]; ny = y + dy[nd];
			pinball(nx, ny, nd);
		}
		else if (map[x][y] >= 6 && map[x][y] <= 10) {
			warmhall(x, y);
			nx = nx + dx[d]; ny = ny + dy[d];
			pinball(nx, ny, d);
		}
		else {
			nx = x + dx[d]; ny = y + dy[d];
			pinball(nx, ny, d);
		}
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	int test; cin >> test;
	for (int t = 1; t <= test; t++) {
		cin >> n;
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				cin >> map[i][j];
				if (map[i][j] >= 6 && map[i][j] <= 10) {
					warm[map[i][j]].push_back({ i,j });
				}
			}
		}
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				if (map[i][j] == 0) {
					for (int k = 0; k < 4; k++) {
						map[i][j] = -2;
						first = true;
						pinball(i, j, k);
						max_cnt = max_cnt < cnt ? cnt : max_cnt;
						cnt = 0;
						map[i][j] = 0;
					}
				}
			}
		}
		cout << "#" << t << " " << max_cnt << "\n";
		max_cnt = -1;
		for (int i = 0; i < 11; i++)
			warm[i].clear();
	}
}
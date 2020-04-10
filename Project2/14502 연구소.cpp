#include <iostream>
#include <queue>
using namespace std;

int n, m; int map[9][9]; int cp[9][9];
int cnt = 0;
queue <pair<int, int>> q;
int max_value = -1;

int dx[] = { -1,1,0,0 };
int dy[] = { 0,0,-1,1 };

void safe_area() {
	cnt = 0;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (cp[i][j] == 0)
				cnt++;
		}
	}
}

void virus() { //바이러스 퍼트림
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (cp[i][j] == 2) //첫번째 2 찾기
			{
				q.push({ i,j });
			}
		}
	}
	while (!q.empty())
	{
		int x = q.front().first; int y = q.front().second;
		q.pop();
		for (int i = 0; i < 4; i++) {
			int nx = x + dx[i]; int ny = y + dy[i];
			if (nx >= 0 && ny >= 0 && nx < n && ny < m) {
				if (cp[nx][ny] == 0) {
					q.push({ nx, ny });
					cp[nx][ny] = 2;
				}
			}
		}
	}
}

void copy() {
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cp[i][j] = map[i][j];
		}
	}
}

void wallmake(int wall_cnt) {
	if (wall_cnt == 3) {
		copy();
		virus();
		safe_area();
		max_value = max_value < cnt ? cnt : max_value;
		return;

	}
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (map[i][j] == 0) {
				map[i][j] = 1;
				wallmake(wall_cnt + 1);
				map[i][j] = 0;
			}
		}
	}
}


int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> map[i][j];
		}
	}

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (map[i][j] == 0) {
				map[i][j] = 1;
				wallmake(1);
				map[i][j] = 0;
			}
		}
	}

	cout << max_value << '\n';

}
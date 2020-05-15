#include <iostream>
#include <vector>
#include <queue>

using namespace std;
int m, n;
int cnt = 0;
int maxnum = 0;
int picture[101][101] = { 0 };
int check[101][101] = { 0 };

int dx[] = { -1,1,0,0 };
int dy[] = { 0,0,-1,1 };
queue<pair<int, int>> q;


void bfs(int x, int y) {
	cnt++; maxnum++;
	check[x][y] = 1; q.push({ x,y });
	while (!q.empty()) {
		x = q.front().first; y = q.front().second;
		q.pop();
		for (int k = 0; k < 4; k++) {
			int nx = x + dx[k], ny = y + dy[k];
			if (0 <= nx && nx < m && 0 <= ny && ny < n) {
				if (picture[x][y] == picture[nx][ny] && check[nx][ny] == 0) {
					q.push({ nx,ny });
					check[nx][ny] = 1;
					maxnum++;
				}
			}
		}
	}

}
int main() {
	int max = -1;
	cin >> m >> n;
	for (int i = 0; i < m; i++) {
		for (int j = 0; j < n; j++) {
			cin >> picture[i][j];
		}
	}
	for (int i = 0; i < m; i++) {
		for (int j = 0; j < n; j++) {
			if (picture[i][j] != 0 && check[i][j] == 0) {
				bfs(i, j);
				if (maxnum > max)
					max = maxnum;
				maxnum = 0;
			}
		}
	}

	cout << cnt << ' ' << max<<'\n';

}
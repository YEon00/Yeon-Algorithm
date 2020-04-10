#include <iostream>
#include <memory.h>
#include <queue>
#include <vector>
using namespace std;

int map[51][51] = { 0 };
int check[51][51] = { 0 };
int cnt = 0;
int w, h;
queue<pair<int, int>> q;
vector<int> v;

int dx[] = { -1,-1,-1,0,0,0,1,1,1 };
int dy[] = { -1,0,1,-1,0,1,-1,0,1 };

void bfs(int x, int y) {
	cnt++;
	check[x][y] = 1; q.push({ x,y });
	while (!q.empty()) {
		x = q.front().first; y = q.front().second;
		q.pop();
		for (int k = 0; k < 9; k++) {
			int nx = x + dx[k];
			int ny = y + dy[k];
			if (nx >= 0 && nx < h && ny >= 0 && ny < w) {
				if (map[nx][ny] == 1 && check[nx][ny] == 0) {
					q.push({ nx,ny });
					check[nx][ny] = 1;
				}
			}
		}
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	while (true) {
		cin >> w >> h;
		if (w == 0 && h == 0) {
			break;
		}
		else
		{
			for (int i = 0; i < h; i++) {
				for (int j = 0; j < w; j++) {
					cin >> map[i][j];
				}
			}
			for (int i = 0; i < h; i++) {
				for (int j = 0; j < w; j++) {
					if (map[i][j] == 1 && check[i][j] == 0) {
						bfs(i, j);
					}
				}
			}
		}
		v.push_back(cnt);
		cnt = 0;
		memset(check, 0, sizeof(check));
	}
	for (int i = 0; i < v.size(); i++) {
		cout << v.at(i) << '\n';
	}
}

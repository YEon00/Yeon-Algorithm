#include <iostream>
#include <queue>

using namespace std;
int n; int cnt = 1;int res = 100;

queue <pair<int, int>> q;

int dx[] = { -1,0,1,0 };
int dy[] = { 0,1,0,-1 };

int map[101][101];
int check[101][101];

bool ch(int x, int y) {
	if (x >= 0 && x < n && y >= 0 && y < n)
		return true;
	else
		return false;
}

void area(int x, int y) {
	map[x][y] = cnt;
	q.push({ x,y });
	while (!q.empty())
	{
		x = q.front().first; y = q.front().second;
		q.pop();
		for (int i = 0; i < 4; i++) {
			int nx = x + dx[i]; int ny = y + dy[i];
			if (ch(nx, ny) && map[nx][ny] == 1) {
				map[nx][ny] = cnt;
				q.push({ nx,ny });
			}
		}
	}
}
int bridge(int x, int y) {
	cnt = 0; 
	q.push({ x,y }); check[x][y] = 1;
	while (!q.empty())
	{
		int s = q.size();
		for (int k = 0; k < s; k++) {
			x = q.front().first; y = q.front().second;
			q.pop();
			for (int i = 0; i < 4; i++) {
				int nx = x + dx[i]; int ny = y + dy[i];
				if (ch(nx, ny)) {
					if (check[nx][ny] != 0 && map[nx][ny] != map[x][y])
						return cnt;
					else if (map[nx][ny] == 0 && check[nx][ny] == 0) {
						check[nx][ny] = 1;
						q.push({ nx,ny });
					}
				}
			}
		}
		cnt++;
	}
	
}

int main() {
	cin >> n;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> map[i][j];
		}
	}
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (map[i][j] == 1) {
				cnt++;
				area(i, j);
			}
		}
	}
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (map[i][j] > 0) {
				res = min(res, bridge(i, j));
				memset(check, 0, sizeof(check));

			}
		}
	}

	cout << res;

	//for (int i = 0; i < n; i++) {
	//	for (int j = 0; j < n; j++) {
	//		cout <<  map[i][j] << ' ' ;
	//	}
	//	cout << "\n";
	//}
}
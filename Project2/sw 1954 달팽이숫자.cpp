#include <iostream>
#include <memory.h>
using namespace std;

int map[11][11];
int check[11][11];

int dx[] = { 0,1,0,-1 };
int dy[] = { 1,0,-1,0 };
int n;
void snail(int x, int y, int cnt,int i) {
	if (cnt > n* n) {
		return;
	}
	if (i > 3) 
		i = 0;
	int nx = x + dx[i]; int ny = y + dy[i];
	if (nx >= 0 && ny >= 0 && nx < n && ny < n && check[nx][ny] != 1) {
		map[nx][ny] = cnt;
		check[nx][ny] = 1;
		cnt++;
		snail(nx, ny, cnt,i);
	}
	else {
		nx = nx - dx[i]; ny = ny - dy[i];
		if (nx >= 0 && ny >= 0 && nx < n && ny < n) {
			i++;
			snail(nx, ny, cnt, i);
		}
	}
}


int main() {
	int t; cin >> t;
	int tc; tc = 1;
	while (t--) {
		
		cin >> n;
		map[0][0] = 1; check[0][0] = 1;
		snail(0, 0, 2,0);
		cout << '#' << tc << '\n';
		
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				cout << map[i][j] << ' ';
			}
			cout << '\n';
		}
		memset(map, 0, sizeof(map));
		memset(check, 0, sizeof(check));

		tc++;

	}
}
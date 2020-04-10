#include <iostream>
#include <queue>
using namespace std;

int a[100][100];
int n; int check[101] = { 0 };
queue <int> q;
int b = 0; int cnt = 0;
void bfs(int x,int y) {
	q.push(x);
	while (!q.empty()) {
		int num = q.front(); q.pop();
		cnt = check[num] + 1;
		for (int i = 1; i <= n; i++) {
			if (a[num][i] == 1 && check[i] == 0) {
				check[i] = cnt; q.push(i);
				if (i == y)
				{
					b = 1;
					break;
				}
			}
		}
		if (b == 1)
			break;
	}
}

int main() {
	 cin >> n;
	int per1, per2; cin >> per1 >> per2;
	int m; cin >> m;
	for (int i = 1; i <= m; i++) {
		int x, y; cin >> x >> y;
		a[x][y] = 1;
		a[y][x] = 1;
	}
	bfs(per1, per2);
	if (check[per2]==0) cnt = -1;
	cout << cnt;
}
#include <iostream>
#include <queue>

using namespace std;

int a[101][101] = { 0 };
int check[101]= {0};
queue <int> q;
queue <int> answer;
int m, n, v;
void bfs(int x) {
	check[x] = 1; q.push(x);
	while (!q.empty()) {
		int num = q.front(); q.pop();
		answer.push(num);
		for (int i = 1; i <= m; i++) {
			if (a[num][i] == 1 && check[i] == 0) {
				check[i] = 1;
				q.push(i);
			}
		}
	}
}


int main() {
	cin >> m >> n >> v;
	for (int i = 0; i < n; i++) {
		int x, y; cin >> x >> y;
		a[x][y] = 1;
	}
	bfs(v);


}
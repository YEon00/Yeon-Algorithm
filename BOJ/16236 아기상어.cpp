#include <iostream>
#include <memory.h>
#include <queue>
using namespace std;

int N; int pre_x, pre_y;
int dist = 0; int fish_size = 2;
int pre_dist;
int res = 0;
int num = 0;
int map[21][21];
bool visited[21][21];
bool check;

int dx[] = { -1,0,1,0 };
int dy[] = { 0,-1,0,1 };

queue <pair<pair<int, int>, int>> q;

bool first(int prex, int prey, int x, int y) { //바꿔야 한다면 true
	if (prex >= x) {
		if (prex == x) {
			if (prey > y) {
				return true;
			}
			return false;
		}
		return true;
	}
	else {
		return false;
	}
		
}

void bfs(int x, int y, int dist) {
	check = false;
	memset(visited, false, sizeof(visited));
	pre_dist = 1;
	if (num == fish_size) {
		num = 0; fish_size++;
	}
	visited[x][y] = true;
	q.push({ { x,y }, dist });
	while (!q.empty()) {
		x = q.front().first.first; 
		y = q.front().first.second;
		dist = q.front().second;
		q.pop();
		if (check && dist != pre_dist) {
			map[pre_x][pre_y] = 0;
			num++; res += pre_dist+1;
			while (!q.empty())
				q.pop();
			dist = 0;
			bfs(pre_x, pre_y, dist);
			return;
		}
		else if (!check && dist != pre_dist) {
			pre_dist = dist;
		}
		for (int i = 0; i < 4; i++) {
			int nx = x + dx[i]; int ny = y + dy[i];
			if (nx >= 0 && ny >= 0 && nx < N && ny < N && !visited[nx][ny]) {
				if (map[nx][ny] <= fish_size) {
					q.push({ {nx,ny}, dist + 1 });
					visited[nx][ny] = true;
					if (map[nx][ny] !=0 &&map[nx][ny] < fish_size) {
						if (!check) {
							check = true;
							pre_x = nx; pre_y = ny;
							pre_dist = dist;
						}
						else {
							if (dist <= pre_dist) {
								if (first(pre_x, pre_y, nx, ny)) {
									pre_x = nx; pre_y = ny;
									pre_dist = dist;
								}

							}
						}
					}
				}
			}		
		}
	}

}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	cin >> N;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			cin >> map[i][j];
			if (map[i][j] == 9) {
				pre_x = i; pre_y = j;
			}
		}
	}
	map[pre_x][pre_y] = 0;
	bfs(pre_x, pre_y, dist);
	cout << res;
}
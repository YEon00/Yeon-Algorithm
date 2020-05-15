#include <iostream>
#include <vector>
#include <queue>
using namespace std;

queue<pair<long, int>> q[102][102];
vector<pair<long, int>> a;
vector<vector<pair<long, int>>> map;
// first = 미생물수 second = 방향

// 상 1 하 2 좌 3 우 4
int dx[] = { 0,-1,1,0,0 };
int dy[] = { 0,0,0,-1,1 };
long total = 0;

int N, M, K;

bool check(int x, int y)
{
	return x > 0 && x < N - 1 && y > 0 && y < N - 1;
}

void calc()
{
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
		{
			total += map[i][j].first;
		}
	}
}

void arrange()
{
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
		{
			int max = 0;
			int dir = 0;
			while (!q[i][j].empty())
			{
				int val = q[i][j].front().first;
				int d = q[i][j].front().second;
				q[i][j].pop();
				if (val > max)
				{
					max = val;
					dir = d;
				}

				map[i][j].first += val;
			}
			map[i][j].second = dir;
		}
	}
}
void solve(int time)
{
	if (time == 0)
	{
		calc();
		return;
	}

	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
		{
			if (map[i][j].first == 0) continue;

			int nx = i + dx[map[i][j].second];
			int ny = j + dy[map[i][j].second];

			if (!check(nx, ny))
			{
				if (nx == 0)
				{
					q[nx][ny].push({ map[i][j].first / 2,2 });
				}
				else if (nx == N - 1)
				{
					q[nx][ny].push({ map[i][j].first / 2,1 });
				}
				else if (ny == 0)
				{
					q[nx][ny].push({ map[i][j].first / 2,4 });
				}
				else if (ny == N - 1)
				{
					q[nx][ny].push({ map[i][j].first / 2,3 });
				}
			}
			else
				q[nx][ny].push({ map[i][j].first,map[i][j].second });
		}
	}

	map.assign(N, a);
	arrange();
	solve(time - 1);
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);

	int t;
	cin >> t;

	for (int tc = 1; tc <= t; tc++)
	{
		cin >> N >> M >> K;
		a.assign(N, { 0,0 });
		map.assign(N, a);
		int x, y;

		for (int i = 0; i < K; i++)
		{
			cin >> x >> y;
			cin >> map[x][y].first >> map[x][y].second;
		}

		solve(M);

		cout << "#" << tc << " " << total << endl;
		total = 0;
	}

	return 0;
}


//#include <iostream>
//#include <memory.h>
//#include <queue>
//using namespace std;
//
//int n, m, k; // 크기, 시간, 미생물 종류
//int res = 0;
//int warm; int direct;
//int x; int y; int d; int warm_cnt;
//int pass = 0;
//int map[101][101] = { 0 };
//int check[101][101] = { 0 };
//int dx[] = { 0,-1,1,0,0 }; //상하좌우
//int dy[] = { 0,0,0,-1,1 };
//
//queue <pair<int, int>> group[10001];
//
//int turn(int d) {
//	if (d == 1) return 2;
//	else if (d == 2) return 1;
//	else if (d == 3) return 4;
//	else if (d == 4) return 3;
//}
//
//void move(int x, int y, int z) {
//	if (check[x][y] == 1) return; 
//	map[x][y] = 0; int next_x = x; int next_y = y;
//	if (group[z].size() <= 1) {
//		warm = group[z].front().first;
//		direct = group[z].front().second;
//		x = x + dx[direct]; y = y + dy[direct];
//	}
//	else {
//		warm = group[z].back().first;
//		direct = group[z].back().second;
//		x = x + dx[direct]; y = y + dy[direct];
//	}
//	
//	if (check[x][y] == 0 && check[next_x][next_y] == 0) {
//		if (map[x][y] != map[next_x][next_y]) {
//			if (abs(x - next_x) == 1 || abs(y - next_y) == 1) {
//				if (abs(group[map[x][y]].front().second - direct) == 1) {
//					pass = 1;
//				}
//			}
//		}
//	}
//	if (x < 1 || x > n - 2 || y < 1 || y > n - 2) { //약품
//		group[z].pop();
//		warm /= 2;
//		int nd = turn(direct);
//		map[x][y] = z;
//		group[z].push({ warm,nd });
//	}
//	else {
//		if (map[x][y] == 0) {
//			map[x][y] = z;
//		}
//		else if (pass == 1) {
//			move(x, y, map[x][y]);
//			map[x][y] = z;
//		}
//		else if (map[x][y] > 0) {
//			int before = map[x][y];
//			if (group[before].size() > 1) { // 더 큰 군집 비교!
//				int before_warm = group[before].front().first;
//				if (before_warm > warm) {
//					group[before].pop(); group[z].pop();
//					warm += group[before].front().first;
//					direct = group[before].front().second;
//					group[before].pop();
//					group[before].push({ before_warm,0 });
//					group[before].push({ warm,direct });
//
//				}
//				else {
//					map[x][y] = z;
//					group[before].pop(); group[z].pop();
//					group[z].push({ warm,0 });
//					warm += group[before].front().first;
//					group[z].push({ warm,direct });
//					group[before].pop();
//				}
//			}
//			else {
//				int before_warm = group[before].front().first;
//				if (before_warm < warm)
//				{
//					map[x][y] = z;
//					group[z].pop(); group[before].pop();
//					group[z].push({ warm,0 }); // 큰 군집 찾기위해 추가
//					warm += before_warm;
//					group[z].push({ warm, direct });
//				}
//				else {
//					map[x][y] = before;
//					warm += before_warm;
//					direct = group[before].front().second;
//					group[z].pop(); group[before].pop();
//					group[before].push({ before_warm,0 });
//					group[before].push({ warm,direct });
//				}
//			}
//
//		}
//	}
//	check[x][y] = 1;
//	pass = 0;
//
//}
//
//
//int main() {
//	int test; cin >> test;
//	for (int t = 1; t <= test; t++) {
//		cin >> n >> m >> k;
//		for (int i = 1; i <= k; i++) {
//			cin >> x >> y >> warm_cnt >> d;
//			map[x][y] = i;
//			group[i].push({ warm_cnt,d });
//		}
//		for (int q = 1; q <= m; q++) {
//			for (int i = 0; i < n; i++) {
//				for (int j = 0; j < n; j++) {
//					if (map[i][j] > 0) {
//						move(i, j, map[i][j]);
//					}
//				}
//			}
//			for (int i = 0; i < 10000; i++) {
//				if (group[i].size() == 2) {
//					group[i].pop();
//				}
//			}
//			memset(check, 0, sizeof(check));
//		}
//		for (int i = 0; i < n; i++) {
//			for (int j = 0; j < n; j++) {
//				if (map[i][j] != 0) {
//					int b = map[i][j];
//					if (group[b].size() > 1)
//						group[b].pop();
//					res += group[b].front().first;
//				}
//			}
//		}
//		cout << "#" << t << " " << res << '\n';
//		res = 0;
//		for (int i = 0; i <= 10000; i++) {
//			if (!group[i].empty())
//				group[i].pop();
//		}
//	}
//}
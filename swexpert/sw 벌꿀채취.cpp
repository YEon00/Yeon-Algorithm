#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <memory.h>

using namespace std;

int N, M, k;

int city[21][21];
int dx[] = { 0,0,-1,1 };
int dy[] = { -1,1,0,0 };
int visit[21][21];
int result = 0;
vector<int> cost;

bool check(int x, int y)
{
	return x >= 1 && x <= N && y >= 1 && y <= N;
}

bool calc(int house, int K)
{
	return house * M - cost[K] >= 0;
}

void BFS(int row, int col)
{
	queue<pair<pair<int, int>, int>> q;
	memset(visit, false, sizeof(visit));

	q.push({ { row,col },1 });
	visit[row][col] = true;
	int K = 1;
	int last_K = 1;
	int house = 0;
	while (!q.empty())
	{
		int x = q.front().first.first;
		int y = q.front().first.second;
		K = q.front().second;
		q.pop();

		if (last_K != K)
		{
			if (calc(house, last_K))
			{
				result = max(result, house);
			}
			last_K = K;
		}
		if (city[x][y] == 1) house++;

		for (int i = 0; i < 4; i++)
		{
			int nx = x + dx[i];
			int ny = y + dy[i];

			if (check(nx, ny) && !visit[nx][ny])
			{
				q.push({ { nx,ny },K + 1 });
				visit[nx][ny] = true;
			}
		}
	}
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);

	int test;
	cin >> test;

	cost.push_back(0);
	for (int i = 1; (i * i) + (i - 1) * (i - 1) <= 4000; i++)
	{
		cost.push_back((i * i) + (i - 1) * (i - 1));
	}

	for (int tc = 1; tc <= test; tc++)
	{
		int home = 0;
		cin >> N >> M;
		for (int i = 1; i <= N; i++)
		{
			for (int j = 1; j <= N; j++)
			{
				cin >> city[i][j];
				if (city[i][j] == 1) home++;
			}
		}

		for (int i = 1;; i++)
		{
			if (home * M < cost[i])
			{
				k = i - 1;
				break;
			}
		}
		for (int i = 1; i <= N; i++)
		{
			for (int j = 1; j <= N; j++)
			{
				BFS(i, j);
			}
		}
		cout << "#" << tc << " " << result << endl;
		result = 0;
	}
	return 0;
}


//#include <iostream>
//#include <vector>
//#include <queue>
//#include <algorithm>
//#include <memory.h>
//using namespace std;
//
//int dx[] = { -1,0,1,0 };
//int dy[] = { 0,1,0,-1 };
//
//int secure[21][21];
//bool visited[21][21];
//
//int res, n, m;
//
//
//
//
//int profit(int x) {
//	return (x * x) + ((x - 1) * (x - 1));
//}
//bool check(int x, int y) {
//	if (x >= 0 && x < n && y >= 0 && y < n)
//		return true;
//	else
//		return false;
//}
//
//void bfs(int x, int y) {
//	int house = 0; int k = 1;
//	queue <pair<int, int>> q;
//	visited[x][y] = true;
//	if (secure[x][y] == 1) house++;
//	q.push({ x,y });
//	while (!q.empty()) {
//		int q_size = q.size();
//		if (k > n + 1) break;
//		if (house * m - profit(k) >= 0)
//			res = max(res, house);
//		for (int i = 0; i < q_size; i++) {
//			int x = q.front().first; int y = q.front().second;
//			q.pop();
//			for (int j = 0; j < 4; j++) {
//				int nx = x + dx[j]; int ny = y + dy[j];
//				if (check(nx, ny) && visited[nx][ny] == false) {
//					visited[nx][ny] = true;
//					q.push({ nx,ny });
//					if (secure[nx][ny] == 1)
//						house++;
//				}
//			}
//		}
//		k++;
//	}
//}
//
//int main() {
//	int test; cin >> test;
//	for (int t = 1; t <= test; t++) {
//		res = 0;
//		memset(visited, false, sizeof(visited));
//		memset(secure, 0, sizeof(secure));
//		cin >> n >> m;
//		for (int i = 0; i < n; i++) {
//			for (int j = 0; j < n; j++) {
//				cin >> secure[i][j];
//			}
//		}
//		for (int i = 0; i < n; i++) {
//			for (int j = 0; j < n; j++) {
//				memset(visited, false, sizeof(visited));
//				bfs(i, j);
//				/*if (res == 10)
//					cout << i << j << '\n';*/
//			}
//		}
//
//		cout << "#" << t << " " << res << "\n";
//	}
//}
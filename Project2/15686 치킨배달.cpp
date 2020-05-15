
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int map[51][51];
int copy_map[51][51];

int n, m; int res;
int distance = 0;
bool visited[13];

vector <pair<int, int>> house, chicken;


void dfs(int x, int check) {
	if (check == m) {
		int temp = 0;
		for (int i = 0; i < house.size(); i++) {
			int min_distance = 99999;
			for (int j = 0; j < chicken.size(); j++) 
				if (visited[j])
				{
					int a = abs(house[i].first - chicken[j].first) + abs(house[i].second - chicken[j].second);
					min_distance = min(min_distance, a);
				}
			
			temp += min_distance;
		}
		res = min(res, temp);
		return;
	}
	if (x == chicken.size())
		return;
	visited[x] = true;
	dfs(x + 1, check + 1);
	visited[x] = false;
	dfs(x + 1, check);
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> map[i][j];
			if (map[i][j] == 1)
				house.push_back({ i,j });
			if (map[i][j] == 2)
				chicken.push_back({ i,j });
		}
	}
	res = 99999;
	dfs(0, 0);
	cout << res << '\n';
}

#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int min_x = 100000; int min_y = 100000;
int max_x = -1; int max_x = -1;
vector <pair<int, pair<int, int>>> v;
bool check[1001];
vector <int> p; vector <int> q;
int w, h;

vector<int> a[1001];

void dfs(int x) {
	check[x] = true;
	
	for (int i = 0; i < a[x].size(); i++) {
		int next = a[x][i];
		if (check[next] == false) {
			p.push_back(v[i].second.first);
			q.push_back(v[i].second.second);
			dfs(next);
		}
	}
}
int main() {
	int n, m; cin >> n >> m;
	
	for (int i = 1; i <= n; i++) {
		int x, y; cin >> x >> y;
		v.push_back({ i, { x,y } });
	}
	for (int i = 1; i <= m; i++) {
		int x, y; cin >> x >> y;
		a[x].push_back(y); a[y].push_back(x);
	}
	for (int i = 1; i <= n; i++) {
		dfs(i);
		sort(p.begin(), p.end());
		sort(q.begin(), q.end());
		w = p[p.size() - 1] - p[0];
		h = q[q.size() - 1] - q[0];

	}
	
	
	
}
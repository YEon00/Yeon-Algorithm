#include <iostream>
#include <vector>

using namespace std;
int jusa[7] = { 0,0,0,0,0,0,0 };
int map[21][21];
int d[1001];
int dx[] = { 0,0,0,-1,1 };
int dy[] = { 0,1,-1,0,0 };
int k, temp;

void dice(int c) {
	switch (c)
	{
	case 1:
		temp = jusa[1];
		jusa[1] = jusa[3];
		jusa[3] = jusa[6];
		jusa[6] = jusa[4];
		jusa[4] = temp;
		break;
	case 2:
		temp = jusa[1];
		jusa[1] = jusa[4];
		jusa[4] = jusa[6];
		jusa[6] = jusa[3];
		jusa[3] = temp;
		break;
	case 3:
		temp = jusa[1];
		jusa[1] = jusa[2];
		jusa[2] = jusa[6];
		jusa[6] = jusa[5];
		jusa[5] = temp;
		break;
	case 4:
		temp = jusa[1];
		jusa[1] = jusa[5];
		jusa[5] = jusa[6];
		jusa[6] = jusa[2];
		jusa[2] = temp;
		break;
	default:
		break;
	}
}


int main() {
	vector <int> v;
	int m, n, x, y;
	cin >> m >> n >> x >> y >> k;
	for (int i = 0; i < m; i++) {
		for (int j = 0; j < n; j++) {
			cin >> map[i][j];
		}
	}
	for (int i = 0; i < k; i++) {
		cin >> d[i];
	}
	for (int i = 0; i < k; i++) {
		int a = d[i];
		x = x + dx[a]; y = y + dy[a];
		if (x >= 0 && x < m && y >= 0 && y < n) {
			dice(a);
			if (map[x][y] != 0) {
				jusa[1] = map[x][y];
				map[x][y] = 0;
			}
			else
				map[x][y] = jusa[1];
			v.push_back(jusa[6]);
		}
		else {
			x = x - dx[a]; y = y - dy[a];
		}
	} //흐아아아아아아아 WHY?!?!?!!?!??!?!!!?!!? 돌았나!?!?!?
	for (int i = 0; i < v.size(); i++) {
		cout << v.at(i) << '\n';
	}
	return 0;
}
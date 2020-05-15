//#include <iostream>
//#include <queue>
//using namespace std;
//
//int map[101][101] = {0};
//int check[101][101] = {0};
//int n; int cnt = 0; int res = 1;
//int min_area = 101;
//int max_area = -1;
//
//int dx[] = { -1,0,1,0 };
//int dy[] = { 0,1,0,-1 };
//
//queue <pair<int, int>>q;
//
//void safezone(int x , int y, int z) {
//	check[x][y] = 1;
//	q.push({ x,y });
//	while (!q.empty()) {
//		x = q.front().first; y = q.front().second;
//		q.pop();
//		for (int k = 0; k < 4; k++) {
//			int nx = x + dx[k], ny = y + dy[k];
//			if (0 <= nx && nx < n && 0 <= ny && ny < n) {
//				if (map[nx][ny] > min_area && check[nx][ny] == 0) {
//					q.push({ nx,ny });
//					check[nx][ny] = 1;
//				}
//			}
//		}
//	}
//	
//}
//
//int main() {
//	cin >> n;
//	for (int i = 0; i < n; i++) {
//		for (int j = 0; j < n; j++) {
//			cin >> map[i][j];
//			min_area = min_area > map[i][j] ? map[i][j] : min_area;
//			max_area = max_area < map[i][j] ? map[i][j] : max_area;
//		}
//	}
//	while (min_area <= max_area )
//	{
//		for (int i = 0; i < n; i++) {
//			for (int j = 0; j < n; j++) {
//				if (check[i][j] == 0 && map[i][j] > min_area) {
//					cnt++;
//					safezone(i, j, min_area);
//				}
//			}
//		}
//		res = res < cnt ? cnt : res;
//		cnt = 0; 
//		memset(check, 0, sizeof(check));
//		min_area++;
//	}
//	cout << res <<'\n';
//	
//}



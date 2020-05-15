//#include <iostream>
//#include<vector>
//#include <queue>
//using namespace std;
//
//int map[1001][1001];
//int max_area = -1; int w = 1;
//bool a = true; int b=0; 
//queue <pair<pair<int, int>,int>> q;
//int dx[] = { 0,1,1 };
//int dy[] = { 1,1,0 };
//// w 를 0으로 해놔야함
//
//void bfs(int x, int y) {
//	q.push({ { x,y },0 });
//	int pre = -1;
//	while (!q.empty()) {
//		x = q.front().first.first; y = q.front().first.second;
//		int gen = q.front().second; //1
//		q.pop();
//		for (int i = 0; i < 3; i++) {
//			int nx = x + dx[i]; int ny = y + dy[i];
//			if (map[nx][ny] == 0) {
//				a = false;
//				break;
//			}
//			else {
//				q.push({{ nx, ny }, gen + 1}); //2
//			}
//		}
//		if (a == false) {
//			max_area = max_area > w* w ? max_area : w * w;
//			return;
//		}
//		if (gen != pre)
//		{
//			pre = gen;
//			w++;
//		}
//	}
//	
//
//}
//
//
//int solution(vector<vector<int>> board)
//{
//	int n = 0;
//	n = board[n].size(); int m = board.size();
//	for (int i = 0; i < m; i++) {
//		for (int j = 0; j < n; j++) {
//			map[i][j] = board[i][j];
//		}
//	}
//	for (int i = 0; i < m; i++) {
//		for (int j = 0; j < n; j++) {
//			if (map[i][j] == 1) {
//				bfs(i, j);
//				w = 1;
//			}
//		}
//	}
//
//	return max_area;
//}

#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int solution(vector<vector<int>> board)
{
	int answer = 0;
	int x = board.size();
	int y = board[0].size();

	for (int i = 0; i < x; i++)
	{
		for (int j = 0; j < y; j++)
		{
			if (i == 0 || j == 0)
			{
				if (board[i][j] == 1 && answer == 0) answer = 1;
				continue;
			}
			if (board[i][j] != 0)
			{
				board[i][j] = min(min(board[i - 1][j - 1], board[i - 1][j]), board[i][j - 1]) + 1;
				answer = (answer < board[i][j] ? board[i][j] : answer);
			}
		}
	}

	return answer * answer;
}

int main()
{
	//vector<vector<int>> v = { {0,1,1,1},{1,1,1,1},{1,1,1,1},{0,0,1,0} };
	//vector<vector<int>> v = { {0,0,1,1},{1,1,1,1} };
	vector<vector<int>> v =
	{
	   {1,1,1,1},
	   {1,1,0,0},
	   {1,0,0,0}
	};
	cout << solution(v);
	return 0;
}
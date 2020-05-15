#include <string>
#include <vector>
#include <iostream>

using namespace std;

int dx[] = { -1,0,1,0 };
int dy[] = { 0,1,0,-1 };

vector<vector<int>> board;
bool visited[26][26];
int straight = 0; int corner = 0;
void dfs(int x, int y) {
	visited[x][y] = true;
	for (int k = 0; k < 4; k++) {

	}
}


int solution(vector<vector<int>> board) {
	int answer = 0;
	dfs(0, 0);
	return answer;
}
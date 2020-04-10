
#include <memory.h>
#include <string>
#include <vector>

using namespace std;

char map[31][31];
int check[31][31] = {0};
bool t = 1;
int answer = 0;

void res(int x, int y) {
	for (int i = 0; i < 2; i++) {
		for (int j = 0; j < 2; j++) {
			if (check[x + i][y + j] != 1) {
				check[x + i][y + j] = 1;
				answer++;
				t = 1;
			}
		}
	}
}

int solution(int m, int n, vector<string> board) {

	while (t)
	{
		t = 0;
		for (int i = 0; i < m-1; i++) {
			for (int j = 0; j < n-1; j++) {
				if (board[i][j] != '#') {
					if (board[i][j] == board[i][j + 1] && board[i][j] == board[i + 1][j]&& board[i][j] == board[i + 1][j + 1]) {
						res(i, j);
					}
				}
			}
		}

		for (int i = m - 1; i > 0; i--) {
			for (int j = n - 1; j >= 0; j--) {
				if (check[i][j] == 1) {
					for (int k = i - 1; k >= 0; k--) {
						if (check[k][j] != 1) {
							board[i][j] = board[k][j];
							board[k][j] = '#';
							check[k][j] = 1;
							check[i][j] = 0;
							break;
						}
					}
				}
			}
		}

		memset(check, 0,sizeof(int));
	}	


	return answer;
}



int main() {
	vector<string> board = { "CCBDE","AAADE","AAABF","CCBBF" };
	solution(4, 5, board);
}
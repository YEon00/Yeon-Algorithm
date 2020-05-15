#include <iostream>
using namespace std;

int num[21];
int n, s;
int cnt = 0; int check = 0;

void dfs(int i, int check) {
	if (i == n) return;
	if (check + num[i] == s)
		cnt++;
	dfs(i + 1, check);
	dfs(i + 1, check + num[i]);
}

int main() {
	
	cin >> n >> s ;
	for (int i = 0; i < n; i++) {
		cin >> num[i];
	}
	dfs(0, 0);
	
}
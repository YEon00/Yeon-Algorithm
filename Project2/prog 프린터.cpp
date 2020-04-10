#include <string>
#include <vector>

using namespace std;

int solution(vector<int> priorities, int location) {
	int answer = 0;
	int check = 0;
	int j = priorities[0];
	for (int i = 1; i < priorities.size(); i++) {
		if (j < priorities[i]) {
			j = priorities[i];
			check = i;
		}
	}
	if (check != 0) {
		for (int i = 0; i < check; i++) {
			priorities.push_back(priorities.front());
		}
	}


	return answer;
}
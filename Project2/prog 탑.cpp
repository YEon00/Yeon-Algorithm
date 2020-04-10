#include <string>
#include <algorithm>
#include <vector>

using namespace std;

vector<int> solution(vector<int> heights) {
	vector<int> answer;
	for (int i = heights.size()-1; i >= 0; i--) {
		int check = 0;
		for (int j = i - 1; j >= 0; j--) {
			if (heights[j] > heights[i]) {
				check = 1;
				answer.push_back(j+1);
				break;
			}
		}
		if (check == 0) {
			answer.push_back(0);
		}
	}
	reverse(answer.begin(), answer.end());

	return answer;
}

int main()
{
	vector<int> a = { 6,9,5,7,4 };

	solution(a);

	return 0;
}
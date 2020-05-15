#include <string>
#include <vector>

using namespace std;

vector<int> solution(vector<int> prices) {
	vector<int> answer;
	for (int i = 0; i < prices.size(); i++) {
		int cnt = 1;
		for (int j = i + 1; j < prices.size(); j++) {
			if (prices[j] >= prices[i])
				cnt++;
			else {
				cnt++;
				break;
			}
		}
		answer.push_back(cnt);
	}
		return answer;
}
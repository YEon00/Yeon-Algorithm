#include <string>
#include <algorithm>
#include <vector>

using namespace std;

bool cmp(const pair<int, float>& a, pair<int, float>& b) {
	if (a.second == b.second)
		return a.first < b.first;
	else
		return a.second > b.second;
}

vector<int> solution(int N, vector<int> stages) {
	vector<int> answer;
	vector<pair<int, float>> ans;
	int cnt = 0;
	int tmp = stages.size();
	for (int i = 1; i <= N; i++) {
		for (int j = 0; j < stages.size(); j++) {
			if (i == stages[j])
				cnt++;
			else
				continue;
		}
		float a = (float)cnt / (float)tmp;
		if (tmp == 0)
			a = 0;
		ans.push_back({ i , a });
		tmp -= cnt; cnt = 0;
	}
	sort(ans.begin(), ans.end(), cmp);
	for (int i = 0; i < ans.size(); i++) {
		answer.push_back(ans[i].first);
	}
	return answer;
}

int main()
{
	vector<int> stages = { 2,1,2,6,2,4,3,3 };
	solution(8, stages);
}
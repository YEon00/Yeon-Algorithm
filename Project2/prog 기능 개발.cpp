#include <string>
#include <vector>

using namespace std;

vector<int> solution(vector<int> progresses, vector<int> speeds) {
	vector<int> answer;
	vector<int> res;
	int cnt = 1; int num=1;
	for (int i = 0; i < progresses.size(); i++) {
		progresses[i] = 100 - progresses[i];
	}
	for (int i = 0; i < speeds.size(); i++) {
		progresses[i] -= (speeds[i]) * cnt;
		while (progresses[i] > 0) {
			cnt++; 
			progresses[i] -= speeds[i];
			if (progresses[i] < 0)
				progresses[i] = -1;
		}
		res.push_back(cnt);
	}
	for (int i = 0; i < res.size(); i++) {
		if (res[i] == res[i + 1])
			num++;
		else {
			if (num > 1) {
				answer.push_back(num);
				num = 1;
			}
			else
				answer.push_back(num);
		}
	}

	return answer;
}

int main()
{
	vector<int> a = { 93,30,55 };
	vector<int> b = { 1,30,5 };

	solution(a, b);


	return 0;
}
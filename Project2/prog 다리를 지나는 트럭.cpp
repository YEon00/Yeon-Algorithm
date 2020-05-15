#include <string>
#include <queue>
#include <vector>

using namespace std;

int solution(int bridge_length, int weight, vector<int> truck_weights) {
	queue <int> q;
	vector <int> truck;
	truck.assign(truck_weights.size(), 0);
	int answer = 0; int time = 1; int pre = weight; int idx = 0;
	int start = 0; q.push(idx);
	pre -= truck_weights[idx]; idx++;
	while (!q.empty()) {
		time++;
		for (int i = start; i < start + q.size(); i++) {
			truck[i]++;
			if (truck[i] == bridge_length) {
				pre += truck_weights[i];
				q.pop();
				start++;
			}
		}
		if (idx < truck_weights.size()) {
			if (pre - truck_weights[idx] >= 0) {
				q.push(idx);
				pre -= truck_weights[idx];
				idx++;
			}

		}
	}
	answer = time;
	
	return answer;
}


int main() {
	vector <int> truck_weight = { 7,4,5,6 };
	solution(2, 10, truck_weight);

	cout << answer << '\n';
}
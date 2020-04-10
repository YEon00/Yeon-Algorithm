#include <string>
#include <algorithm>
#include <vector>
#include <deque>

using namespace std;
//int *arr = new int[입력받은상수];
int solution(int cacheSize, vector<string> cities) {
	deque <string> d;
	int answer = 0;
	if (cacheSize == 0) {
		answer += 5 * cities.size();
		return answer;
	}
	for (int i = 0; i < cities.size(); i++) {

		int j = 0;
		int size;
		transform(cities[i].begin(), cities[i].end(), cities[i].begin(), ::tolower);
		if (d.empty()) size = 0;
		else size = d.size();
		for (j = 0; j < size; j++) {
			if (cities[i] == d[j])
			{
				d.erase(d.begin() + j);
				d.push_back(cities[i]);
				answer += 1;
				break;
			}

		}
		if (j == size) {
			answer += 5;
			if (size >= cacheSize) {
				d.pop_front();
			}
			d.push_back(cities[i]);
		}

	}

	return answer;

}
int main() {
	vector<string> str = { "a","a","c","c","a","A","d","c","f","z" };
	solution(3,str);
}

#include <iostream>
#include <set>
#include <vector>
#include <algorithm>
#include <string>

using namespace std;
//set은 키가 중복이 안되는 정렬!
//transform(cities[i].begin(), cities[i].end(), cities[i].begin(), ::tolower);
//v2.erase(v2.begin()+j);
//vector <string> ::iterator iter;
//

bool check(char x) {
	return ('a' <= x && 'z' >= x);
}



int solution(string str1, string str2) {

	int answer, cnt = 0;
	string a, b;
	vector <string> v1;
	vector <string> v2;

	for (int i = 0; i < str1.length(); i++) {
		str1[i] = tolower(str1[i]);
	}
	for (int i = 0; i < str2.length(); i++) {
		str2[i] = tolower(str2[i]);
	}

	if (str1 == str2) {
		return 65536;
	}
	for (int i = 0; i < str1.length() - 1; i++) {
		if (check(str1[i]) && check(str1[i + 1])) {
			a += str1[i];
			a += str1[i + 1];
			v1.push_back(a);

			a.clear();
		}
	}
	for (int i = 0; i < str2.length() - 1; i++) {
		if (check(str2[i]) && check(str2[i + 1])) {
			b += str2[i];
			b += str2[i + 1];
			v2.push_back(b);
			b.clear();
		}

	}
	sort(v1.begin(), v1.end());
	sort(v2.begin(), v2.end());
	float res = v1.size() + v2.size();
	for (int i = 0; i < v1.size(); i++) {
		for (int j = 0; j < v2.size(); j++) {
			if (v1[i] == v2[j]) {
				cnt++;
				v2.erase(v2.begin()+j);
				break;
			}
		}
	}
	res -= cnt;
	res = (float)cnt / res;
	answer = res * 65536;

	return answer;
}

int main() {
	string str1 = "france";
	string str2 = "french";
	solution(str1, str2);
}
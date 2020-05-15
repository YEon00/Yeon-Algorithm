#include <string>
#include <vector>

using namespace std;
//str.substr(5,1) 5번째 인자부터 1길이 만큼 반환


int solution(string s) {
	int answer = 0;
	string temp;
	int min = 1001;
	int cnt = 1;
	if (s.size() == 1) {
		answer = 1;
	}
	for (int i = 1; i <= s.size() / 2; i++) { //개수 늘리는 반까지 돌아갈꺼야
		for (int j = 0; j < s.size(); j += i) { // 
			for (int k = i; k < s.size(); k + i) { // 1 
				if (k + j > s.size())
				{
					temp += s.substr(j, i);
					break;
				}
				else if (s.substr(j, i) == s.substr(j + k, i)) { // 0,1 1,1  
					cnt++;
					break;
				}
				else {
					if (cnt > 1) {
						temp += to_string(cnt);
						temp += s.substr(j, i);
						cnt = 1;
						break;
					}
					else {
						temp += s.substr(j, i);
						break;
					}
				}
			}
		}
		if (min > temp.size())
			min = temp.size();
		temp = "";
	}
	answer = min;
	return answer;
}

int main() {
	string s = "a";
	solution(s);
}
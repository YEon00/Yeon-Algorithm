#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <set>

using namespace std;

vector<int> solution(vector<string> gems) {
	vector<int> answer;
	set <pair<string,bool>> s;
	for (int i = 0; i < gems.size; i++) {
		s.insert({gems[i], false});
	}
	int length = s.size();
	int num = 0; int first = 0; int end = 0;
	for (int i = 0; i < gems.size(); i++) {
		if (s.count({ gems[i],false }) == 1) {
			num++;
			
		}
		

	}
	

	return answer;
}
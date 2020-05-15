#include <iostream>
#include <string>
#include <sstream>
#include <vector>
#include <algorithm>

using namespace std;

char op[4] = { '+','-','*','/' };
vector <int> v;
long long solution(string expression) {
	long long answer = 0;
	for (int i = 0; i < expression.size(); i++) {
		bool check = false;
		if (i % 2 == 1) {
			for(int j=0;j<v.size();j++){
				if (expression[i] == v[j]) {
					check = true;
				}
			}
			if (!check) {
				for (int j = 0; j < 4; j++) {
					if (op[j] == expression[i]) {
						v.push_back(j);
					}
				}
			}

		}
	}
	int num; int temp = 0;
	string copy = expression;
	stringstream ss(copy);
	do {
		while (ss>>num)
		{
			char pre_op;
			pre_op = ss.get();
			for (int i = 0; i < v.size(); i++) {
				if(pre_op )
			}
		}
	} while (next_permutation(v.begin(), v.end()));





	return answer;
}
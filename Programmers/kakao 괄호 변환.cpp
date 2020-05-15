#include <string>
#include <sstream>
#include <vector>

using namespace std;

bool correct(string s) {
	int cr=0;
	for (int i = 0; i < s.size(); i++) {
		if (s[i] == '(')
			cr++;
		else cr--;
		if (cr < 0) {
			return false;
		}
	}
	if (cr == 0)
		return true;
	else
		return false;
}

string solution(string p) {
	string answer = "";
	int check = 0;
	stringstream ss;
	ss.str(p);
	string u, v;
	char a;
	if (p == "") {
		return "";
	}
	for (; ss >> a;) {
		if (a == '(') check++;
		else check--;
		u += a;
		if (check == 0) {
			ss >> v;
			break;
		}
	}
	if (correct(u)) {
		answer += u;
		answer += solution(v);
	}
	else {
		string b; b += "(";
		b += solution(v);
		b += ")";
		for (int i = 1; i < u.size()-1; i++) {
			if (u[i] == '(')
				b += ')';
			else b += '(';
		}
		answer += b;
	}

	return answer;
}

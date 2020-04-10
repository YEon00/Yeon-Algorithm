#include <string>
#include <map>
#include <sstream>
#include <vector>

using namespace std;

vector<string> solution(vector<string> record) {
	vector<string> answer;
	map<string, string> m;
	for (int i = 0; i<record.size(); i++) {
		string cmd,id,name;
		stringstream ss;
		ss.str(record[i]);
		ss >> cmd;
		if (cmd == "Enter") {
			ss >> id;
			ss >> name;
			if (m.find(id) == m.end()) {
				m.insert({ id,name });
			}
			else 
				m[id] = name;
		}
		else if (cmd == "Change") {
			ss >> id;
			ss >> name;
			if (m.find(id) != m.end())
				m[id] = name;
		}
	}
	for (int i = 0; i < record.size(); i++) {
		string cmd, id;
		stringstream ss;
		ss.str(record[i]);
		ss >> cmd;
		if (cmd == "Enter") {
			ss >> id;
			answer.push_back(m[id] + "님이 들어왔습니다.");
		}
		else if (cmd == "Leave") {
			ss >> id;
			answer.push_back(m[id] + "님이 나갔습니다.");
		}
		else
			continue;
	}
	return answer;
}

int main() {
	vector <string> record = { "Enter 1234 Muzi","Enter 4567 Prodo" ,"Leave 1234 Muzi","Enter 1234 prodo","Change 4567 Ryan" };
	solution(record);
}
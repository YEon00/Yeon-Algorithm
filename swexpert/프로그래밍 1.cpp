#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <map>
using namespace std;

map<string, int> m;
map<string, int>::iterator iter;
vector<vector<string>> answer;

void trade(string s,string name,int n) {
	if (s == "SAVE") {
		int money = m[name] + n;
		m[name] = money;
	}
	else {
		int money = m[name] - n;
		m[name] = money;
	}
}

vector<vector<string>> solution(vector<vector<string>> snapshots, vector<vector<string>> transactions) {

	for (int i = 0; i < snapshots.size(); i++) {
		string s = snapshots[i][0];
		int money = stoi(snapshots[i][1]);
		m.insert({ s,money });
	}
	//sort(transactions.begin(), transactions.end());
	transactions.erase(unique(transactions.begin(), transactions.end()), transactions.end());
	for (int i = 0; i < transactions.size(); i++) {
		iter = m.find(transactions[i][2]);
		if (iter != m.end()) {
			trade(transactions[i][1], transactions[i][2] ,stoi(transactions[i][3]));
		}
		else {
			m.insert({ transactions[i][2] ,stoi(transactions[i][3]) });
		}
	}
	for (iter = m.begin(); iter != m.end(); iter++) {
		string s = iter->first;
		int n = iter->second;
		vector <string> v;
		v.push_back(s); v.push_back(to_string(n));
		answer.push_back(v);
		v.clear();
	}
	return answer;
}

int main() {
	vector<vector<string>> snapshots = { {"ACCOUNT1","100"},{"ACCOUNT2","150"} };
	vector<vector<string>> transactions = { {"1", "SAVE", "ACCOUNT2", "100"},{"2", "WITHDRAW", "ACCOUNT1", "50"},
	{"1", "SAVE", "ACCOUNT2", "100"},{"4", "SAVE", "ACCOUNT3", "500"},{"4", "WITHDRAW", "ACCOUNT3", "50"},{"4", "SAVE", "ACCOUNT3", "500"} };
	solution(snapshots,transactions);
	for (int i = 0; i < answer.size(); i++) {
		cout << answer[i][0]<<" " << answer[i][1] <<'\n';
	}

}

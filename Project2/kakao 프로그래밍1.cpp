#include <iostream>
#include <string>
#include <queue>
#include <vector>

using namespace std;
string key[4][3] = { {"1","2","3"},{"4","5","6"},{"7","8","9"},{"*","0","#"} };
int pre = 0; int pre1 = 0;
void check(string s) {
	for (int i = 0; i < 4; i++) {
		for (int j = 0; j < 3; j++) {
			if (s == key[i][j])
			{
				pre = i; pre1 = j;
				return;
			}
		}
		
	}
}

string solution(vector<int> numbers, string hand) {
	string answer = ""; string Hand;
	queue <pair<int, int>> Left;
	queue <pair<int, int>> Right;
	Left.push({ 3,0 }); Right.push({3,2 });
	if (hand == "right")
		Hand = "R";
	else
		Hand = "L";
	for (int i = 0; i < numbers.size(); i++) {
		int distance = 0, distance1 = 0;
		string a = to_string(numbers[i]);
		pre = 0; pre1 = 0;
		if (numbers[i] == 1 || numbers[i] == 4 || numbers[i] == 7) {
			answer += "L"; check(a);
			Left.pop();
			Left.push({ pre,pre1 });
			continue;
		}
		if (numbers[i] == 3 || numbers[i] == 6 || numbers[i] == 9) {
			answer += "R"; check(a);
			Right.pop();
			Right.push({ pre,pre1 });
			continue;
		}
		else {
			if (i - 1 < 0)
			{
				if (Hand == "L")
				{
					check(a);
					Left.pop();
					Left.push({ pre,pre1 });
					answer += Hand;
				}
				else {
					check(a);
					Right.pop();
					Right.push({ pre,pre1 });
					answer += Hand;
				}
			}
			else {
				if (numbers[i] == 2 || numbers[i] == 5 || numbers[i] == 8 || numbers[i] == 0) {
					check(a);
					distance = abs(Left.front().first - pre) + abs(Left.front().second - pre1);
					distance1 = abs(Right.front().first - pre) + abs(Right.front().second - pre1);
					if (distance == distance1) {
						if (Hand == "L")
						{
							Left.pop();
							Left.push({ pre,pre1 }); 
							answer += Hand;
						}
						else {
							Right.pop();
							Right.push({ pre,pre1 });
							answer += Hand;
						}
					}
					else {
						if (distance < distance1) {
							answer += "L";
							Left.pop();
							Left.push({ pre,pre1 });
						}
						else {
							answer += "R";
							Right.pop();
							Right.push({ pre,pre1 });
						}
					}
				}
			}
		}
	}
	return answer;
}

int main()
{
	vector<int> n = { 2,0,1,8,5,0};
	string h = "left";

	cout << solution(n, h);

	return 0;
}
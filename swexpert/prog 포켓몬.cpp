#include <vector>
#include <iostream>
#include <algorithm>
#include <set>
using namespace std;

int solution(vector<int> nums)
{
	int answer = 0;
	int size = nums.size() / 2;
	sort(nums.begin(), nums.end());
	nums.erase(unique(nums.begin(), nums.end()), nums.end());
	if (nums.size() < size) {
		answer = nums.size();
	}
	else
		answer = size;
	
	
	return answer;


}

int main() {
	vector <int> v = { 1,200,200,1,1,1,100,100 };
	solution(v);

}
#include <iostream>
using namespace std;

int main() {
	int N; 
	int idx = 1;
	cin >> N;
	for (int i = 0; i < N; i++)
	{
		int x,y; 
		cin >> x >> y;

		if (x == idx)
		{
			idx = y;
		}
		else if (y == idx)
		{
			idx = x;
		}
	}
	cout << idx;

}


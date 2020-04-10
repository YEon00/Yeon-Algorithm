#include <iostream>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	long long a, b, v; cin >> a >> b >> v;
	long long temp = 0, time = 0;
	temp = a - b;
	time = (v - b - 1) / (temp);
	time += 1;
	cout << time;
}
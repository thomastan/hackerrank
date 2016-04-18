// http://hackerrank.com/challenges/tutorial-intro
#include <iostream>
#include <vector>
using namespace std;

int main() {
	int x, n;
	cin >> x >> n;

	vector<int> v;
	for (int i = 0, y; i < n; i++) {
		cin >> y;
		v.push_back(y);
	}

	for (int i = 0; i < n; i++)
		if (v[i] == x)
			cout << i << endl;

	return 0;
}

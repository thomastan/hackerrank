// http://hackerrank.com/challenges/service-lane
#include <iostream>
using namespace std;

int minWidth(int width[], int start, int end) {
	int min = 3;
	for (int i = start; i <= end; i++)
		if (width[i] < min)
			min = width[i];

	return min;
}

int main() {
	int N, T;
	cin >> N >> T;

	int width[N];
	for (int i = 0; i < N; i++)
		cin >> width[i];

	for (int t = 0; t < T; t++) {
		int i, j;
		cin >> i >> j;
		cout << minWidth(width, i, j) << endl;
	}

	return 0;
}

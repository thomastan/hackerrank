// http://hackerrank.com/challenges/maxsubarray
#include <iostream>
#include <vector>
#include <limits>
using namespace std;

int kadaneSum(const vector<int> &a) {
	int maxAtIndex = a[0], maxSum = a[0];

	for (int i = 1; i < a.size(); i++) {
		if (a[i] >= maxAtIndex + a[i])
			maxAtIndex = a[i];
		else
			maxAtIndex = maxAtIndex + a[i];

		if (maxSum < maxAtIndex)
			maxSum = maxAtIndex;
	}

	return maxSum;
}

int maxSum(const vector<int> &a) {
	int sum = 0, count = 0;
	for (int i = 0; i < a.size(); i++)
		sum += a[i] >= 0 ? count++, a[i] : 0;

	if (count == 0) {
		// everything negative, return max element (least negative element)
		int max = numeric_limits<int>::min();
		for (int i = 0; i < a.size(); i++)
			max = a[i] > max ? a[i] : max;
		return max;
	}

	return sum;
}

int main() {
	int T, n;

	cin >> T;
	for (int i = 0; i < T; i++) {
		cin >> n;

		vector<int> v;
		for (int j = 0, x; j < n; j++) {
			cin >> x;
			v.push_back(x);
		}

		cout << kadaneSum(v) << ' ' << maxSum(v) << endl;
	}

	return 0;
}

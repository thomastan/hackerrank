// http://hackerrank.com/challenges/sherlock-and-array
#include <iostream>
using namespace std;

bool equalSubarrays(int A[], int n) {
	unsigned long long rightSum = 0, leftSum = 0;

	for (int i = 0; i < n; i++)
		rightSum += A[i];

	for (int i = 0; i < n; i++) {
		leftSum += i == 0 ? 0 : A[i - 1];
		rightSum -= A[i];
		if (leftSum == rightSum)
			return true;
	}

	return false;
}

int main() {
	int T;
	cin >> T;

	for (int t = 0; t < T; t++) {
		int N;
		cin >> N;

		int A[N];
		for (int i = 0; i < N; i++)
			cin >> A[i];

		cout << (equalSubarrays(A, N) ? "YES" : "NO") << endl;
	}
	return 0;
}

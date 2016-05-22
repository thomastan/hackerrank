// http://hackerrank.com/challenges/angry-professor
#include <iostream>
using namespace std;

bool cancelClass(int a[], const int k, const int n) {
	int numEarly = 0;

	for (int i = 0; i < n; i++)
		if (a[i] <= 0)
			numEarly++;

	return numEarly < k;
}

int main() {
	int T;
	cin >> T;

	for (int i = 0; i < T; i++) {
		int N, K;
		cin >> N >> K;

		int a[N];
		for (int j = 0; j < N; j++)
			cin >> a[j];

		cout << (cancelClass(a, K, N) ? "YES" : "NO") << endl;
	}

	return 0;
}

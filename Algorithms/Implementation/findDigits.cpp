// http://hackerrank.com/challenges/find-digits
#include <iostream>
using namespace std;

int countEvenDivisions(const int N) {
	int n = N, numDivisible = 0, lastDigit;
	while (n) {
		lastDigit = n % 10;
		if (lastDigit != 0 && N % lastDigit == 0)
			numDivisible++;

		n /= 10;
	}

	return numDivisible;
}

int main() {
	int T;
	cin >> T;

	for (int t = 0; t < T; t++) {
		int N;
		cin >> N;

		cout << countEvenDivisions(N) << endl;
	}
}

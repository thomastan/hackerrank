// http://hackerrank.com/challenges/sherlock-and-the-beast
#include <iostream>
#include <string>
using namespace std;

string repeat(const char x, const int times) {
	string generated = "";
	for (int i = 0; i < times; i++)
		generated += x;

	return generated;
}

string sherlock(const int n) {
	if (n < 3)
		return "-1";

	if (n % 3 == 0)
		return repeat('5', n);

	// Start with the maximum number of 5's, then reduce that amount by 1 set
	// and add the required amount of 3's to get to N. If adding a multiple
	// amount of 3's causes the length of the string to go past N, reduce the
	// amount of 5's again.

	int numFiveSets = n / 3;
	string fives = repeat('5', n / 3 * 3);

	int maxThreeSets = n / 5, numThreeSets;

	for (numThreeSets = 1; numThreeSets <= maxThreeSets && numFiveSets >= 0;
		 numThreeSets++)
		if (numFiveSets * 3 + numThreeSets * 5 == n)
			return fives + repeat('3', 5 * numThreeSets);
		else if (fives.length() + 5 * numThreeSets > n) {
			fives = fives.substr(0, fives.length() - 3);
			numFiveSets--;
			numThreeSets--;  // repeat loop with fewer 5's
		}

	return "-1";
}

int main() {
	int T, n;
	cin >> T;

	for (int i = 0; i < T; i++) {
		cin >> n;
		cout << sherlock(n) << endl;
	}
}

// http://hackerrank.com/challenges/alternating-characters
#include <iostream>
#include <string>
using namespace std;

int countDeletions(string s) {
	int numConsecutive = 0;
	for (int i = 1; i < s.length(); i++)
		if (s[i] == s[i - 1])
			numConsecutive++;

	return numConsecutive;
}

int main() {
	int T;
	cin >> T;

	for (int i = 0; i < T; i++) {
		string s;
		cin >> s;

		cout << countDeletions(s) << endl;
	}
	return 0;
}

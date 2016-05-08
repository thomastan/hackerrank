// http://hackerrank.com/challenges/the-love-letter-mystery
#include <iostream>
#include <string>
using namespace std;

int diff(char c, char d) {
	return c - d < 0 ? d - c : c - d;
}

int countChanges(string s) {
	int count = 0, n = s.length();

	for (int i = 0; i < n / 2; i++)
		if (s[i] != s[n - 1 - i])
			count += diff(s[i], s[n - 1 - i]);

	return count;
}

int main() {
	int T;
	cin >> T;

	for (int i = 0; i < T; i++) {
		string s;
		cin >> s;

		cout << countChanges(s) << endl;
	}
	return 0;
}

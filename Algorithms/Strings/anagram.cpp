// http://hackerrank.com/challenges/anagram
#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

int countDifferences(const string &a, const string &b) {
	int inA[26] = {0}, inB[26] = {0};

	for (int i = 0; i < a.length(); i++) {
		inA[a[i] - 'a']++;
		inB[b[i] - 'a']++;
	}

	int exclusiveInA = 0, exclusiveInB = 0;
	for (int i = 0; i < 26; i++) {
		exclusiveInB += max(inB[i] - inA[i], 0);
		exclusiveInA += max(inA[i] - inB[i], 0);
	}

	if (exclusiveInA != exclusiveInB)
		return -1;

	return exclusiveInB;
}

int main() {
	short T;
	cin >> T;

	for (short t = 0; t < T; t++) {
		string s, a, b;
		cin >> s;

		if (s.length() % 2 != 0)
			cout << -1 << endl;
		else {
			a = s.substr(0, s.length() / 2);
			b = s.substr(s.length() / 2);

			cout << countDifferences(a, b) << endl;
		}
	}

	return 0;
}

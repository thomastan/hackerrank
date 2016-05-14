// http://hackerrank.com/challenges/make-it-anagram
#include <iostream>
#include <string>
using namespace std;

int numDeletions(const string &a, const string &b) {
	int inA[26] = {0}, inB[26] = {0};

	for (int i = 0; i < a.length(); i++)
		inA[a[i] - 'a']++;
	for (int i = 0; i < b.length(); i++)
		inB[b[i] - 'a']++;

	int numUnmatched = 0;
	for (int i = 0; i < 26; i++)
		if (inA[i] != inB[i])
			numUnmatched += abs(inA[i] - inB[i]);

	return numUnmatched;
}

int main() {
	string a, b;
	cin >> a >> b;

	cout << numDeletions(a, b) << endl;
}

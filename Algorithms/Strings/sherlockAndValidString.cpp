// http://hackerrank.com/challenges/sherlock-and-valid-string
#include <iostream>
#include <map>
#include <string>
using namespace std;

bool removeOne(const string &s) {
	int count[26] = {0};

	for (int i = 0; i < s.length(); i++)
		count[s[i] - 'a']++;

	map<int, int> occurance;
	// count the different amount of frequencies
	for (int i = 0; i < 26; i++)
		occurance[count[i]]++;  // freq vs diff letters occuring this many times

	// find the most common frequency (it->first == freq, it->second == #types)
	int mostCommon = -1, howManyChars = -1;
	map<int, int>::iterator it;
	for (it = occurance.begin(); it != occurance.end(); it++)
		if (it->second >= howManyChars && it->first != 0) {
			if (it->second == howManyChars) {
				// if m chars appears x times, and a different m chars occur y
				// times, pick the smaller.
				mostCommon = min(mostCommon, it->first);
			} else
				mostCommon = it->first;

			howManyChars = it->second;
		}

	bool foundOne = false;
	for (int i = 0; i < 26; i++) {
		if (count[i] == 0 || count[i] == mostCommon)
			continue;

		if (count[i] > mostCommon + 1)
			return false;

		if (count[i] < mostCommon && count[i] > 1)
			return false;

		// find one excessive letter
		if (count[i] == mostCommon + 1 || count[i] == 1) {
			if (foundOne == false)
				foundOne = true;  // first excessive letter found, search more
			else  // an excessive letter found, but one other already found
				return false;
		}
	}

	return true;
}

int main() {
	string s;
	cin >> s;

	cout << (removeOne(s) ? "YES" : "NO") << endl;
}

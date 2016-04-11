// http://hackerrank.com/challenges/pangrams
#include <iostream>
#include <string>
using namespace std;

bool pangram(const char *s) {
	const unsigned tableSize = 'Z' - 'A' + 1;
	bool charsUsed[tableSize] = {false};

	while (*s) {
		if (*s >= 'A' && *s <= 'Z')
			charsUsed[*s - 'A'] = true;
		else if (*s >= 'a' && *s <= 'z')
			charsUsed[*s - 'a'] = true;

		s++;
	}

	for (int i = 0; i < tableSize; i++)
		if (!charsUsed[i])
			return false;

	return true;
}

int main() {
	string s;
	getline(cin, s);

	cout << (pangram(s.c_str()) ? "pangram" : "not pangram") << endl;
	return 0;
}

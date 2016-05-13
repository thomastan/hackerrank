// http://hackerrank.com/challenges/game-of-thrones
#include <iostream>
#include <string>
using namespace std;

bool makePalindrome(string &s) {
	unsigned short letterCount[26] = {0};

	for (int i = 0; i < s.length(); i++)
		letterCount[s[i] - 'a']++;

	int unmatched = 0;
	for (int i = 0; i < 26; i++)
		if (letterCount[i] % 2 != 0)
			unmatched++;

	return unmatched <= 1 ? true : false;
}

int main() {
	string s;
	cin >> s;

	cout << (makePalindrome(s) ? "YES" : "NO") << endl;
}

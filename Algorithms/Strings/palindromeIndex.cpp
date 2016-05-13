// http://hackerrank.com/challenges/palindrome-index
#include <iostream>
#include <string>
using namespace std;

bool isPalindrome(string s) {
	for (int i = 0; i < s.length() / 2; i++)
		if (s[i] != s[s.length() - 1 - i])
			return false;
	return true;
}

int palindromeIndex(string s) {
	for (int i = 0; i < s.length() / 2; i++)
		if (s[i] != s[s.length() - 1 - i]) {
			string leftChopped = s.substr(i + 1, s.length() - 1 - 2 * i);
			string rightChopped = s.substr(i, s.length() - 1 - 2 * i);

			if (isPalindrome(leftChopped))
				return i;
			else if (isPalindrome(rightChopped))
				return s.length() - 1 - i;
		}
	return -1;
}

int main() {
	int T;
	cin >> T;

	for (int i = 0; i < T; i++) {
		string s;
		cin >> s;

		cout << palindromeIndex(s) << endl;
	}
	return 0;
}

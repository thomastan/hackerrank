// https://www.hackerrank.com/challenges/two-strings
#include <iostream>
#include <string>
using namespace std;

bool checkSubstrings(const char *A, const char *B) {
	// Iterate over the smallest possible substrings in A and B (each character)
	// to search in the other string.  If the other string contains this
	// character, interrupt the search and return true.  Return false at search
	// exhaustion.

	// For efficiency: creating an index of which characters are in A, and
	// search each character of B in the index.  Then create and search B's
	// index for each character in A and return false if no characters are
	// found.

	// index's of a and b
	bool inA[57], inB[57];  // 'A'->'Z' = 65->90, 'a'->'z' = 97->122: 122-65=57
	for (int i = 0; i < 57; i++)
		inA[i] = inB[i] = false;
	const char *a = A, *b = B;

	// populate inA with characters
	while (*a) {
		if (('A' <= *a && *a <= 'Z') || ('a' <= *a && *a <= 'z'))
			inA[*a - 'A'] = true;
		a++;
	}

	// search inA for each of b's characters (and create b's index at the same
	// time)
	while (*b) {
		if (('A' <= *b && *b <= 'Z') || ('a' <= *b && *b <= 'z')) {
			if (inA[*b - 'A'])
				return true;
			inB[*b - 'A'] = true;
		}
		b++;
	}

	a = A, b = B;
	// search inB for each of a's characters
	while (*a) {
		if (('A' <= *a && *a <= 'Z') || ('a' <= *a && *a <= 'z'))
			if (inB[*a - 'A'])
				return true;
		a++;
	}

	return false;
}

int main() {
	int T;
	cin >> T;

	for (int i = 0; i < T; i++) {
		string a, b;
		cin >> a >> b;

		cout << (checkSubstrings(a.c_str(), b.c_str()) ? "YES" : "NO") << endl;
	}

	return 0;
}

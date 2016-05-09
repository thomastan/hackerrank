// http://hackerrank.com/challenges/gem-stones
#include <iostream>
#include <string>
using namespace std;

int min(int a, int b) {
	return a < b ? a : b;
}

int main() {
	int N;
	cin >> N;

	unsigned count[26] = {0};
	for (int i = 0; i < N; i++) {
		string s;
		cin >> s;

		unsigned appearance[26] = {0};
		for (int j = 0; j < s.length(); j++)
			appearance[s[j] - 'a'] = 1;

		for (int k = 0; k < 26; k++)
			count[k] += appearance[k];
	}

	unsigned inAll = 0;
	for (int i = 0; i < 26; i++)
		if (count[i] == N)
			inAll++;

	cout << inAll << endl;
	return 0;
}

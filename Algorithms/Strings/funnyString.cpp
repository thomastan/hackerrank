// http://hackerrank.com/challenges/funny-string
#include <iostream>
#include <string>
using namespace std;

int diff(char a, char b) {
	return a > b ? a - b : b - a;
}

string funniness(string S) {
	string R;
	for (int i = 0; i < S.size(); i++)
		R.insert(R.begin(), S[i]);

	for (int j = 1; j < S.size(); j++)
		if (diff(S[j], S[j - 1]) != diff(R[j], R[j - 1]))
			return "Not Funny";

	return "Funny";
}

int main() {
	int T;
	cin >> T;

	string S;
	for (int i = 0; i < T; i++) {
		cin >> S;
		cout << funniness(S) << endl;
	}
	return 0;
}

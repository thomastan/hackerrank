// http://hackerrank.com/challenges/countingsort4
#include <iostream>
#include <vector>
#include <string>
using namespace std;

void print(vector<unsigned> listing[], string s[], int m) {
	for (int i = 0; i < m; i++)
		for (int j = 0; j < listing[i].size(); j++)
			cout << s[listing[i][j]] << ' ';
	cout << endl;
}

int main() {
	int n;
	cin >> n;

	vector<unsigned> *a = new vector<unsigned>[n];
	string *toPrint = new string[n], s;
	for (int i = 0, x; i < n; i++) {
		cin >> x >> s;

		a[x].push_back(i);
		toPrint[i] = (i < n / 2) ? "-" : s;
	}

	print(a, toPrint, n);
	delete[] a;
	delete[] toPrint;
}

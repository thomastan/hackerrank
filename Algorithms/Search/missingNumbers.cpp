// http://hackerrank.com/challenges/missing-numbers
#include <iostream>
using namespace std;

void missingNumbers(int a[], int b[], int n, int m) {
	int count[10001] = {0};

	for (int i = 0; i < n; i++)
		count[a[i]]--;
	for (int i = 0; i < m; i++)
		count[b[i]]++;

	for (int i = 1; i <= 10000; i++)
		if (count[i] > 0)
			cout << i << ' ';
}

int main() {
	int n;
	cin >> n;

	int a[n];
	for (int i = 0; i < n; i++)
		cin >> a[i];

	int m;
	cin >> m;

	int b[m];
	for (int i = 0; i < m; i++)
		cin >> b[i];

	missingNumbers(a, b, n, m);
	return 0;
}

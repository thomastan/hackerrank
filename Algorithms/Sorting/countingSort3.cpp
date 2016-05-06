// http://hackerrank.com/challenges/countingsort3
#include <iostream>
#include <string>
using namespace std;

void print(int count[], int m) {
	for (int i = 0, soFar = 0; i < m; i++) {
		soFar += count[i];
		cout << soFar << (i == m - 1 ? '\n' : ' ');
	}
}

void countingSort(int a[], int n) {
	int count[100] = {0};

	for (int i = 0; i < n; i++)
		count[a[i]]++;

	print(count, 100);
}

int main() {
	int n;
	cin >> n;

	int a[n];
	string s;
	for (int i = 0; i < n; i++)
		cin >> a[i] >> s;

	countingSort(a, n);
}

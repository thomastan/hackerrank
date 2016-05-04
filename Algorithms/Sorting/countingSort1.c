// http://hackerrank.com/challenges/countingsort1
#include <stdio.h>

void print(int count[], int m) {
	for (int i = 0; i < m; i++)
		printf("%d%c", count[i], i == m - 1 ? '\n' : ' ');
}

void countingSort(int a[], int n) {
	int count[100] = {0};

	for (int i = 0; i < n; i++)
		count[a[i]]++;

	print(count, 100);
}

int main() {
	int n;
	scanf("%d", &n);

	int a[n];
	for (int i = 0; i < n; i++)
		scanf("%d", &a[i]);

	countingSort(a, n);
}

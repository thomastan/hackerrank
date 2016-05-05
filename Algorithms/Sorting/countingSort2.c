// http://hackerrank.com/challenges/countingsort2
#include <stdio.h>

void print(int count[], int m) {
	for (int i = 0; i < m; i++)
		if (count[i] > 0)
			for (int j = 0; j < count[i]; j++)
				printf("%d%c", i, i == m - 1 && j == count[i] - 1 ? '\n' : ' ');
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

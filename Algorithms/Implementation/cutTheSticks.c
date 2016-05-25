// http://hackerrank.com/challenges/cut-the-sticks
#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

int findMinPositive(int a[], int N) {
	int min = INT_MAX;
	for (int i = 0; i < N; i++)
		if (a[i] < min && a[i] > 0)
			min = a[i];
	return min;
}

void printRemaining(int a[], int N) {
	for (int i = 0, count = -1, oldCount = -1, min; count != 0; i++) {
		count = 0, min = i > 0 ? findMinPositive(a, N) : 0;
		for (int j = 0; j < N; j++) {
			a[j] -= min;
			if (a[j] > 0)
				count++;
		}

		if (count == 0)
			break;
		if (count != oldCount)
			printf("%d\n", count);
		oldCount = count;
	}
}

int main() {
	int N;
	scanf("%d", &N);

	int i, a[N];
	for (i = 0; i < N; i++)
		scanf("%d", &a[i]);

	printRemaining(a, N);
}

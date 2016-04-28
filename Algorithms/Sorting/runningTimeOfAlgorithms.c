// http://hackerrank.com/challenges/runningtime
#include <stdio.h>

int insertionSort(int N, int arr[]) {
	int i, j, value, k;
	int numShifts = 0;

	for (i = 1; i < N; i++) {
		value = arr[i];
		for (j = i - 1; j >= 0 && value < arr[j]; j--)
			arr[j + 1] = arr[j];

		arr[j + 1] = value;
		numShifts += (i - j);
	}

	return numShifts;
}

int main() {
	int N;
	scanf("%d", &N);

	int arr[N], i;
	for (i = 0; i < N; i++)
		scanf("%d", &arr[i]);

	printf("%d\n", insertionSort(N, arr));

	return 0;
}

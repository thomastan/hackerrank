// http://hackerrank.com/challenges/insertionsort2
#include <stdio.h>

void insertionSort(int N, int arr[]) {
	int i, j, value, k;

	for (i = 1; i < N; i++) {
		value = arr[i];
		for (j = i - 1; j >= 0 && value < arr[j]; j--)
			arr[j + 1] = arr[j];

		arr[j + 1] = value;
		for (k = 0; k < N; k++)
			printf("%d%c", arr[k], k == N - 1 ? '\n' : ' ');
	}
}

int main() {
	int N;
	scanf("%d", &N);

	int arr[N], i;
	for (i = 0; i < N; i++)
		scanf("%d", &arr[i]);

	insertionSort(N, arr);
	return 0;
}

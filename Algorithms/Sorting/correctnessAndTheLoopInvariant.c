// http://hackerrank.com/challenges/correctness-invariant
#include <stdio.h>

void insertionSort(int N, int arr[]) {
	int i, j, value;

	for (i = 1; i < N; i++) {
		value = arr[i];
		j = i - 1;
		while (j >= 0 && value < arr[j]) {
			arr[j + 1] = arr[j];
			j--;
		}
		arr[j + 1] = value;
	}

	for (j = 0; j < N; j++)
		printf("%d%c", arr[j], j == N - 1 ? '\n' : ' ');
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

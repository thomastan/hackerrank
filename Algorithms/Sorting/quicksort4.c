// http://hackerrank.com/challenges/quicksort4
#include <stdio.h>

int insertionSort(int N, int arr[]) {
	int i, j, value, k;
	int numShifts = 0;

	for (i = 1; i < N; i++) {
		value = arr[i];
		for (j = i - 1; j >= 0 && value < arr[j]; j--)
			arr[j + 1] = arr[j];

		arr[j + 1] = value;
		numShifts += i - (j + 1);
	}

	return numShifts;
}

int sort(int a[], int n, int first, int last);
int partition(int a[], int left, int right, int *partitionShifts);

int quickSort(int n, int a[]) {
	return sort(a, n, 0, n - 1);
}

int sort(int a[], int n, int first, int last) {
	int partitionShifts = 0, shiftsLeft = 0, shiftsRight = 0;

	if (first < last) {
		int index = partition(a, first, last, &partitionShifts);
		shiftsLeft = sort(a, n, first, index - 1);
		shiftsRight = sort(a, n, index + 1, last);
	}

	return partitionShifts + shiftsLeft + shiftsRight;
}

int partition(int a[], int left, int right, int *numShifts) {
	int pivot = a[right];

	// place all elements smaller than the pivot on the left
	int index = left, temp;
	for (int i = left; i < right; i++)
		if (a[i] <= pivot) {
			temp = a[index], a[index] = a[i], a[i] = temp;
			index++;
			(*numShifts)++;
		}

	// place the pivot immediately after all these smaller elements
	a[right] = a[index], a[index] = pivot;
	(*numShifts)++;
	return index;
}

int main() {
	int N;
	scanf("%d", &N);

	int a[N], b[N], i;
	for (i = 0; i < N; i++) {
		scanf("%d", &a[i]);
		b[i] = a[i];
	}

	printf("%d\n", insertionSort(N, a) - quickSort(N, b));
	return 0;
}

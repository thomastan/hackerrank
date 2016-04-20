// http://hackerrank.com/challenges/find-median
#include <stdio.h>

int quickselect(int a[], int n, int k);
int select(int a[], int left, int right, int k);
int partition(int a[], int left, int right, int k);

int quickselect(int a[], int n, int k) {
	return select(a, 0, n - 1, k);
}

int select(int a[], int left, int right, int k) {
	int pivotIndex = partition(a, left, right, k);

	if (k == pivotIndex)
		return a[k];
	else if (k < pivotIndex)
		return select(a, left, pivotIndex - 1, k);
	else
		return select(a, pivotIndex + 1, right, k);
}

int partition(int a[], int left, int right, int k) {
	int pivot = a[k];  // try finding the k-th smallest in slot k

	a[k] = a[right], a[right] = pivot;

	// place all elements smaller than the pivot on the left
	int index = left, temp;
	for (int i = left; i < right; i++)
		if (a[i] < pivot) {
			temp = a[index], a[index] = a[i], a[i] = temp;
			index++;
		}

	// place the pivot immediately after all these smaller elements
	temp = a[index], a[index] = a[right], a[right] = temp;
	return index;
}

int main() {
	int n;
	scanf("%d", &n);

	int num[n];
	for (int i = 0, x; i < n; i++)
		scanf("%d", &num[i]);

	printf("%d\n", quickselect(num, n, n / 2));

	return 0;
}
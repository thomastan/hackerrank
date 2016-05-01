// http://hackerrank.com/challenges/quicksort2
#include <stdio.h>

void sort(int a[], int first, int last);
int partition(int a[], int left, int right);
void print(int a[], int left, int right);

void quickSort(int n, int a[]) {
	sort(a, 0, n - 1);
}

void sort(int a[], int first, int last) {
	if (first < last) {
		int index = partition(a, first, last);
		sort(a, first, index - 1);
		sort(a, index + 1, last);

		print(a, first, last);
	}
}

int partition(int a[], int left, int right) {
	int pivot = a[left];

	int b[right - left + 1], numInLeft = 0;   // holds elements < pivot
	int c[right - left + 1], numInRight = 0;  // holds elements > pivot

	for (int i = left + 1; i <= right; i++)
		if (a[i] <= pivot)
			b[numInLeft++] = a[i];  // copy element into left array
		else
			c[numInRight++] = a[i];  // copy element into right array

	int numInCombined = 0, pivotIndex;  // copy elements back to a[]
	for (int i = left; i <= right; i++)
		if (numInCombined < numInLeft)
			a[i] = b[numInCombined++];
		else if (numInCombined == numInLeft)
			a[i] = pivot, pivotIndex = i, numInCombined++;
		else
			a[i] = c[numInCombined++ - (numInLeft + 1)];

	return pivotIndex;
}

void print(int a[], int left, int right) {
	for (int i = left; i <= right; i++)
		printf("%d%c", a[i], i == right ? '\n' : ' ');
}

int main() {
	int n;
	scanf("%d", &n);
	int a[n], i;
	for (i = 0; i < n; i++)
		scanf("%d", &a[i]);

	quickSort(n, a);
	return 0;
}

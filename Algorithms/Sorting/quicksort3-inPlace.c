// http://hackerrank.com/challenges/quicksort3
#include <stdio.h>

void sort(int a[], int n, int first, int last);
int partition(int a[], int left, int right);
void print(int a[], int left, int right);

void quickSort(int n, int a[]) {
	sort(a, n, 0, n - 1);
}

void sort(int a[], int n, int first, int last) {
	if (first < last) {
		int index = partition(a, first, last);
		print(a, 0, n - 1);
		sort(a, n, first, index - 1);
		sort(a, n, index + 1, last);
	}
}

int partition(int a[], int left, int right) {
	int pivot = a[right];

	// place all elements smaller than the pivot on the left
	int index = left, temp;
	for (int i = left; i < right; i++)
		if (a[i] <= pivot) {
			temp = a[index], a[index] = a[i], a[i] = temp;
			index++;
		}

	// place the pivot immediately after all these smaller elements
	a[right] = a[index], a[index] = pivot;
	return index;
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

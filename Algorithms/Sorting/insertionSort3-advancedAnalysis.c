// http://hackerrank.com/challenges/insertion-sort
#include <stdio.h>

long mergesortWithInsertionSortCount(int a[], int n);
long partition(int a[], int left, int right);
long merge(int a[], int left, int mid, int right);

long mergesortWithInsertionSortCount(int a[], int n) {
	return partition(a, 0, n - 1);
}

long partition(int a[], int left, int right) {
	long count = 0;
	if (left != right) {
		int mid = left + (right - left) / 2;

		count += partition(a, left, mid);
		count += partition(a, mid + 1, right);

		return count + merge(a, left, mid, right);
	}
	return 0;
}

long merge(int a[], int left, int mid, int right) {
	int i = left, j = mid + 1, k = 0;
	int sorted[right - left];

	long inversions = 0;
	while ((i <= mid) && (j <= right))
		if (a[i] <= a[j]) {
			sorted[k] = a[i], i++;
			inversions += j - (mid + 1), k++;
		} else
			sorted[k++] = a[j], j++;

	// increment number of inversions by (number of elements remaining in left
	// array) * (elements from right array already in sorted array).
	if (i <= mid)
		inversions += (long) (mid - i + 1) * (j - (mid + 1));
	while (i <= mid)
		sorted[k++] = a[i++];
	while (j <= right)
		sorted[k++] = a[j++];

	for (i = left, k = 0; i <= right; i++, k++)
		a[i] = sorted[k];
	return inversions;
}

int main() {
	// An inversion is when an element in the left array is less than the
	// element in the right array in the merge routine.  Whenever an element is
	// taken from the left array, the number of inversions can be incremented by
	// the number of elements already copied from the right array into to the
	// merged array.
	int T;
	scanf("%d", &T);

	for (int t = 0; t < T; t++) {
		int N;
		scanf("%d", &N);

		int arr[N], i;
		for (i = 0; i < N; i++)
			scanf("%d", &arr[i]);

		printf("%ld\n", mergesortWithInsertionSortCount(arr, N));
	}

	return 0;
}

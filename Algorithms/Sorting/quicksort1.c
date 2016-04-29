// http://hackerrank.com/challenges/quicksort1
#include <stdio.h>

int partition(int ar_size, int ar[]) {
	int pivot = ar[0];

	// place pivot at the end
	ar[0] = ar[ar_size - 1], ar[ar_size - 1] = pivot;

	// place all elements smaller than the pivot on the left
	int index = 0, temp;
	for (int i = 0; i < ar_size - 1; i++)
		if (ar[i] <= pivot) {
			temp = ar[index], ar[index] = ar[i], ar[i] = temp;
			index++;
		}

	// place the pivot immediately after all these smaller elements
	ar[ar_size - 1] = ar[index], ar[index] = pivot;
	return index;
}

int main() {
	int _ar_size;
	scanf("%d", &_ar_size);
	int _ar[_ar_size], _ar_i;
	for (_ar_i = 0; _ar_i < _ar_size; _ar_i++) {
		scanf("%d", &_ar[_ar_i]);
	}

	partition(_ar_size, _ar);

	for (int i = 0; i < _ar_size; i++)
		printf("%d%c", _ar[i], i == _ar_size - 1 ? '\n' : ' ');

	return 0;
}

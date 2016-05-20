// http://hackerrank.com/challenges/sherlock-and-watson
#include <stdio.h>
#include <stdlib.h>  // qsort()

int compare(const void *a, const void *b) {
	return *(int *) a - *(int *) b;
}

unsigned long long countPairs(int n) {
	return (unsigned long long) (((long) n) * ((long) (n - 1)));
}

int main() {
	int T;
	scanf("%d", &T);

	for (int t = 0; t < T; t++) {
		int N;

		scanf("%d", &N);
		int a[N];
		for (int i = 0; i < N; i++)
			scanf("%d", &a[i]);

		qsort(a, N, sizeof(int), compare);

		// count how many times each number occurs and perform nPr, r = 2.
		unsigned long long numPairs = 0;
		int i;
		for (i = 0; i < N - 1; i++) {
			// printf("i=%d\n", i);
			if (a[i + 1] == a[i]) {
				int j, numRepeats;
				for (j = i, numRepeats = 0; a[j] == a[i] && j < N; j++)
					numRepeats++;  // how many times this number is repeated

				numPairs += countPairs(numRepeats);
				i = j - 1;  // skip i along j times (loop increments i again)
			}
		}
		// printf("i=%d\n", i);

		printf("%d\n", numPairs);
	}

	return 0;
}

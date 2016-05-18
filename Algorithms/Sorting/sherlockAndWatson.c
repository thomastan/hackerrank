// http://hackerrank.com/challenges/sherlock-and-watson
#include <stdio.h>

int main() {
	int N, K, Q;

	scanf("%d %d %d", &N, &K, &Q);
	int a[N];
	for (int i = 0; i < N; i++)
		scanf("%d", &a[(i + K) % N]);

	for (int i = 0, j; i < Q; i++) {
		scanf("%d", &j);
		printf("%d\n", a[j]);
	}

	return 0;
}

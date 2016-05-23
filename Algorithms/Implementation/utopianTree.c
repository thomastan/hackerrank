// http://hackerrank.com/challenges/utopian-tree
#include <stdio.h>

int utopian(const int N) {
	int height = 1, i;

	for (i = 1; i <= N; i++)
		if (i % 2 == 1)
			height <<= 1;
		else
			height++;

	return height;
}

int main() {
	int T, i, N;
	scanf("%d\n", &T);

	for (i = 0; i < T; i++) {
		scanf("%d", &N);
		printf("%d\n", utopian(N));
	}
	return 0;
}

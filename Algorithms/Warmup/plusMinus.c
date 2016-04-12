// http://hackerrank.com/challenges/plus-minus
#include <stdio.h>

int main() {
	int n;
	scanf("%d", &n);

	int i, x, arr[3] = {0, 0, 0};
	for (i = 0; i < n; i++) {
		scanf("%d", &x);

		if (x < 0)
			arr[0]++;
		else if (x == 0)
			arr[1]++;
		else
			arr[2]++;
	}

	printf("%0.6f\n", (float) arr[2] / n);
	printf("%0.6f\n", (float) arr[0] / n);
	printf("%0.6f\n", (float) arr[1] / n);
	return 0;
}

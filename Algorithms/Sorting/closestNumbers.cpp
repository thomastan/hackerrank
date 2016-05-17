// http://hackerrank.com/challenges/closest-numbers
#include <iostream>
#include <cstdlib>  //qsort, abs, bsearch
#include <limits>
#include <map>
using namespace std;

int compare(const void *a, const void *b) {
	return *(int *) a - *(int *) b;
}

int findSmallestDiff(int a[], int n) {
	unsigned min = numeric_limits<int>::max();
	for (int i = 1; i < n; i++)
		if (abs(a[i] - a[i - 1]) < min)
			min = abs(a[i] - a[i - 1]);

	return min;
}

multimap<int, int> getPairsWithDiff(int diff, int a[], int n) {
	multimap<int, int> pairs;

	for (int i = 0; i < n; i++) {
		int *leftIndex = NULL, *rightIndex = NULL;

		// search if (a[i] - diff) is in the sublist a[0]...a[i - 1]
		int left = a[i] - diff;
		if (i > 0)
			leftIndex = (int *) bsearch(&left, a, i - 1, sizeof(int), compare);
		if (leftIndex)
			pairs.insert(make_pair(a[i] - diff, a[i]));

		int right = a[i] + diff;
		if (i < n - 1)
			rightIndex =
				(int *) bsearch(&right, a + i, n - i, sizeof(int), compare);
		if (rightIndex)
			pairs.insert(make_pair(a[i], a[i] + diff));
	}

	return pairs;
}

int main() {
	// sort: O(n lg n), O(n^2) worst case for quicksort, O(n lg n) for mergesort
	// find smallest diff: O(n)
	// find if i +- smallest diff is in sorted list for each i = 1..n: O(n lg n)
	// total = O(n lg n) or O(n^2) + O(n) + O(n * lg n)

	int N;
	cin >> N;

	int a[N];
	for (int i = 0; i < N; i++)
		cin >> a[i];

	qsort(a, N, sizeof(int), compare);
	int min = findSmallestDiff(a, N);

	// get and print smallest pairs
	multimap<int, int> pairs = getPairsWithDiff(min, a, N);
	for (multimap<int, int>::iterator i = pairs.begin(); i != pairs.end(); i++)
		cout << i->first << ' ' << i->second << ' ';
	cout << end;

	return 0;
}

// http://hackerrank.com/challenges/candies
#include <iostream>
#include <algorithm>  // for max()
using namespace std;

unsigned long long countCandies(int rating[], int n) {
	unsigned count[n];
	for (int i = 0; i < n; i++)
		count[i] = 1;

	for (int i = 1; i < n; i++)
		if (rating[i] > rating[i - 1])
			count[i] = count[i - 1] + 1;

	for (int i = n - 2; i >= 0; i--)
		if (rating[i] > rating[i + 1])
			count[i] = max(count[i], count[i + 1] + 1);

	unsigned long long totalCandies = 0;
	for (int i = 0; i < n; i++)
		totalCandies += count[i];

	return totalCandies;
}

int main() {
	int N;
	cin >> N;

	int rating[N];
	for (int i = 0; i < N; i++)
		cin >> rating[i];

	cout << countCandies(rating, N) << endl;
	return 0;
}

// http://hackerrank.com/challenges/pairs
#include <iostream>
#include <map>
using namespace std;

int countPairs(int a[], const int N, const int K) {
	map<int, bool> available;

	for (int i = 0; i < N; i++)
		available[a[i]] = true;

	int count = 0;
	for (int i = 0; i < N; i++)
		if (available.find(a[i] + K) != available.end())
			count++;

	return count;
}

int main() {
	int N, K;
	cin >> N >> K;

	int a[N];  // c99 valid, but not valid in pedantic c++. use stack for faster
			   // performance than heap
	for (int i = 0; i < N; i++)
		cin >> a[i];

	cout << countPairs(a, N, K) << endl;
	return 0;
}

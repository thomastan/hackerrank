// http://hackerrank.com/challenges/chocolate-in-box
#include <iostream>
using namespace std;

int countOptimalMoves(const int heap[], const int N, const int nimSum) {
	// In Nim, the optimal move to to make is to reduce the the heap whose
	// amount when xor'd with the Nim sum decreases.  The amount to reduce the
	// heap to is the amount the heap is decreased to.

	int moves = 0;
	for (int i = 0; i < N; i++)
		if ((heap[i] ^ nimSum) < heap[i])
			moves++;
	return moves;
}

int main() {
	int N;
	cin >> N;

	int a[N], nimSum = 0;
	for (int i = 0; i < N; i++) {
		cin >> heap[i];
		nimSum ^= heap[i];
	}

	cout << countOptimalMoves(heap, N, nimSum) << endl;

	return 0;
}

// http://hackerrank.com/challenges/sherlock-and-squares
#include <iostream>
#include <cmath>
using namespace std;

int countSquares(int A, int B) {
	int a = ceil(sqrt(A));
	int b = floor(sqrt(B));

	int count = 0;
	for (int i = a; i <= b; i++)
		count++;

	return count;
}

int main() {
	int T, A, B;
	cin >> T;

	for (int i = 0; i < T; i++) {
		cin >> A >> B;
		cout << countSquares(A, B) << endl;
	}
}

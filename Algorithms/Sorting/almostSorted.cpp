// http://hackerrank.com/challenges/almost-sorted
#include <iostream>
#include <vector>
#include <algorithm>  // for reverse()
using namespace std;

bool inSequence(vector<int> &check, int start = 0) {
	for (int i = start; i < check.size() - 1; i++)
		if (check[i] > check[i + 1])
			return false;
	return true;
}

enum method { exchange, mirror };  // swap, reverse keywords taken by std::

struct Result {
	bool isSorted;
	bool doChange;
	method how;
	int a, b;  // swap(a, b) or reverse[a, b)
};

// Find an inversion (or peak), then find the end of the inversion (or find a
// second peak).  Helper function above checks the remainder to ensure multiple
// changes are not required.
Result check(vector<int> &a) {
	bool checkingReverse = false;
	int firstLocation;

	Result result;
	result.isSorted = true;
	result.doChange = false;
	result.a = 0, result.b = 1;

	// Find the first peak (third tested condition below)
	for (int i = 0; i < a.size() - 1; i++) {
		if (checkingReverse) {  // continue scanning, look for end of inversion
			if (a[i] < a[i + 1]) {  // found end of inversion
				cerr << "Found end of inversion at " << i << endl;

				if (inSequence(a, i + 1)) {
					result.doChange = true;
					result.how = (i == firstLocation + 1 ? exchange : mirror);
					result.a = firstLocation, result.b = i;
					return result;
				}  // look for second peak
				checkingReverse = false;
			}
		}

		else if (!result.isSorted) {  // found one peak (inversion), find next
			if (a[i] > a[i + 1]) {	// found another peak
				cerr << "Found second inversion at " << i + 1 << endl;
				if (inSequence(a, i + 1)) {
					result.doChange = true, result.how = exchange;
					result.a = firstLocation, result.b = i + 1;
					return result;
				} else  // multiple problems found
					return result;
			}
		}

		else if (a[i] > a[i + 1]) {  // find first peak
			cerr << "Found first inversion at " << i << endl;
			result.isSorted = false, checkingReverse = true, firstLocation = i;
		}
	}

	if (a.size() == 2)  // need special case as loop was broken 1 before end
		if (a[0] < a[1])
			result.isSorted = true;
		else
			result.doChange = true, result.how = exchange;

	return result;
}

int main() {
	int n;
	cin >> n;

	vector<int> a;
	for (int i = 0, x; i < n; i++) {
		cin >> x;
		a.push_back(x);
	}

	Result r = check(a);
	// The check could return an insufficient change.  Example:
	//
	//    *                  *
	//    * *              * *
	//    * *   *  ->      * * *
	//    * * * *        * * * *
	//  * * * * *      * * * * *
	//
	//  1 5 4 2 3  ->  1 2 4 5 3
	//  1(5,4,2)3  ->  1(2,4,5)3
	//
	// We therefore need to verify the changes

	if (r.doChange)  // single change found, check if it corrects sequence
		if (r.how == mirror) {  // try reverse[start, end)
			reverse(a.begin() + r.a, a.begin() + r.b + 1);
			if (inSequence(a)) {
				cout << "yes" << endl;
				cout << "reverse " << r.a + 1 << " " << r.b + 1 << endl;
			} else
				cout << "no" << endl;  // insufficient reverse

		} else {  // try swap
			int temp = a[r.a];
			a[r.a] = a[r.b], a[r.b] = temp;

			if (inSequence(a)) {
				cout << "yes" << endl;
				cout << "swap " << r.a + 1 << " " << r.b + 1 << endl;
			} else
				cout << "no" << endl;  // insufficient swap
		}
	else  // no fixes to be made
		cout << (r.isSorted ? "yes" : "no") << endl;

	return 0;
}

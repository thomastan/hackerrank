#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

unsigned numDistinctInSequence(const unsigned N, const unsigned S,
                               const unsigned P, const unsigned Q) {
    constexpr unsigned divBy = 1 << 31;
    vector<bool> a(divBy, false);  // a[i]==true means it occurs
    unsigned prev = S % divBy;

    a[prev] = true;
    unsigned count = 1;
    for (unsigned i = 1, curr; i < N; ++i) {
        curr = (prev * P + Q) % divBy;
        if (a[curr]) break;  // want to break early
        a[curr] = true;
        ++count;
        prev = curr;
    }

    return count;
}

int main() {
    unsigned N, S, P, Q;
    cin >> N >> S >> P >> Q;

    cout << numDistinctInSequence(N, S, P, Q) << endl;
    return 0;
}

#include <iostream>
#include <deque>
#include <algorithm>
using namespace std;

void printKMax(const int arr[], const int n, const int k) {
    // fill a deque of size K, and find it's max as an ITERATOR

    // for insertion of each a[i], i = k...n-1
    // if iterator points to element to be removed:
    //    remove the front, add to the back, recalculate max_iterator
    // else check the new element if it will exceed the iteartor's element
    //    if so, pop the front, add to the back, set the new iterator to back-1
    //    otherwise: pop the front, add to the back, keep the iterator the same

    deque<int> d;
    for (int i = 0; i < k; ++i)
        d.push_back(arr[i]);
    auto windowMax = max_element(d.begin(), d.end());
    cout << *windowMax;

    for (int i = k; i < n; ++i) {
        if (windowMax == d.begin()) {
            d.pop_front();
            d.push_back(arr[i]);
            windowMax = max_element(d.begin(), d.end());
        } else {
            d.pop_front();
            d.push_back(arr[i]);
            if (d.back() > *windowMax)
                windowMax = prev(d.end());
        }

        cout << ' ' << *windowMax;
    }

    cout << endl;
}

int main() {
    int t, n, k;
    cin >> t;
    while (t--) {
        cin >> n >> k;
        int arr[n];
        for (int i = 0; i < n; ++i)
            cin >> arr[i];
        printKMax(arr, n, k);
    }
    return 0;
}
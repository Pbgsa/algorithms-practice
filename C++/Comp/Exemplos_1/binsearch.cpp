// C - Binary search 
#include <iostream>
#include <algorithm>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, q;
    cin >> n >> q;
    int arr[n];
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }   

    // Aready sorted
    // sort(arr, arr + n);

    while (q--) {
        int x;
        cin >> x;
        auto it = lower_bound(arr, arr + n, x);
        if (it != arr + n && *it == x) {
            cout << (it - arr) << "\n";
        } else {
            cout << -1 << "\n";
        }
    }

    return 0;
}
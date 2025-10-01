// A - Distinct Numbers  
#include <iostream>
#include <algorithm>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;
    int arr[n];
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    sort(arr, arr + n);
    int distinct_count = 1; // At least one distinct element exists
    for (int i = 1; i < n; i++) {
        if (arr[i] != arr[i - 1]) {
            distinct_count++;
        }
    }
    cout << distinct_count << "\n";
}
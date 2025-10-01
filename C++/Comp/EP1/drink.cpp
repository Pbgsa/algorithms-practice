#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;

    int prices[n];
    for (int i = 0; i < n; i++) {
        cin >> prices[i];
    }

    sort(prices, prices + n);

    int q;
    cin >> q;

    for (int i = 0; i < q; i++) {
        int m, total_n;
        cin >> m;

        auto it = upper_bound(prices, prices + n, m);
        total_n = (it - prices -1);
        if (total_n >= 0) {
            cout << (total_n + 1) << "\n";
        } else {
            cout << 0 << "\n";
        }
    }
}
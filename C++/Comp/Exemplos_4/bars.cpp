#include <bits/stdc++.h>
using namespace std;

#define pb push_back
#define all(v) v.begin(), v.end()
using ll = long long;

void isPossibleToFormLength(int n, const vector<int>& bars_lengths) {
    vector<bool> dp(n + 1, false);
    dp[0] = true;

    for (int length : bars_lengths) {
        for (int j = n; j >= length; j--) {
            if (dp[j - length]) {
                dp[j] = true;
            }
        }
    }

    if (dp[n]) {
        cout << "YES\n";
    } else {
        cout << "NO\n";
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;

    while (t--) {
        int n;
        cin >> n;

        int p;
        cin >> p;

        vector<int> bars_lengths(p);
        for (int i = 0; i < p; i++) {
            cin >> bars_lengths[i];
        }

        sort(all(bars_lengths));

        isPossibleToFormLength(n, bars_lengths);
    }

    return 0;
}
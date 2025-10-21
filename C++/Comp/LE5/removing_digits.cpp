#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;

    vector<int> dp(n + 1, INT_MAX);
    dp[0] = 0;

    for (int i = 1; i <= n; i++) {
        string s = to_string(i);
        for (char c : s) {
            int d = c - '0';
            dp[i] = min(dp[i], dp[i - d] + 1);
        }
    }

    cout << dp[n] << "\n";

    return 0;
}
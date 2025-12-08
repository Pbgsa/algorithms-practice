#include <bits/stdc++.h>
using namespace std;
using ll = long long;

const ll MOD = 1000000007LL;

bool match(const string &T, int i, const string &w) {
    int n = T.size();
    int m = w.size();
    if (i + m > n) {
        return false;
    }

    for (int k = 0; k < m; k++) {
        if (T[i+k] != '?' && T[i+k] != w[k]) {
            return false;
        }
    }
    return true;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;
    vector<string> words(n);
    for (int i = 0; i < n; i++) {
        cin >> words[i];
    }

    string T;
    cin >> T;

    int N = T.size();
    vector<ll> dp(N+1, 0);
    dp[N] = 1;

    for (int i = N-1; i >= 0; i--) {
        ll ways = 0;
        for (auto &w : words) {
            if (match(T, i, w)) {
                ways = (ways + dp[i + w.size()]) % MOD;
            }
        }
        dp[i] = ways;
    }

    cout << dp[0] << "\n";
    return 0;
}

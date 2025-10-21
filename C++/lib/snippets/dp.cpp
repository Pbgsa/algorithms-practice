#include <bits/stdc++.h>
using namespace std;
using ll = long long;

/* Resolve problemas dividindo-os em subproblemas menores e 
armazenando resultados para evitar recomputação.*/

// 0/1 Knapsack Problem
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, W;
    cin >> n >> W;
    vector<int> weight(n), value(n);
    for (int i = 0; i < n; i++) cin >> weight[i] >> value[i];

    vector<vector<ll>> dp(n + 1, vector<ll>(W + 1, 0));

    for (int i = 1; i <= n; i++) {
        for (int w = 0; w <= W; w++) {
            dp[i][w] = dp[i - 1][w]; // não pega o item
            if (w >= weight[i - 1])
                dp[i][w] = max(dp[i][w],
                               dp[i - 1][w - weight[i - 1]] + value[i - 1]);
        }
    }

    cout << dp[n][W] << "\n";
}

// Longest Increasing Subsequence (LIS)
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;
    vector<int> a(n);
    for (int &x : a) cin >> x;

    vector<int> dp;
    for (int x : a) {
        auto it = lower_bound(dp.begin(), dp.end(), x);
        if (it == dp.end()) dp.push_back(x);
        else *it = x;
    }

    cout << dp.size() << "\n";
}

// Coin Change (Mínimo de Moedas – DP)
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, target;
    cin >> n >> target;
    vector<int> coins(n);
    for (int &c : coins) cin >> c;

    vector<int> dp(target + 1, 1e9);
    dp[0] = 0;

    for (int c : coins)
        for (int v = c; v <= target; v++)
            dp[v] = min(dp[v], dp[v - c] + 1);

    cout << (dp[target] == 1e9 ? -1 : dp[target]) << "\n";
}

// Kadane’s Algorithm (Maximum Subarray Sum)
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;
    vector<long long> a(n);
    for (auto &x : a) cin >> x;

    long long best = a[0], current = a[0];
    for (int i = 1; i < n; i++) {
        current = max(a[i], current + a[i]);
        best = max(best, current);
    }

    cout << best << "\n";
}
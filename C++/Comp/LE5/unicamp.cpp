#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int X, N; 
    cin >> X >> N;
    vector<pair<int, ll>> cars(N);
    for (int i = 0; i < N; i++) {
        cin >> cars[i].first >> cars[i].second;
    }

    const ll INF = 1e18;
    vector<ll> dp(X + 1, INF);
    dp[0] = 0;

    for (auto [p, v] : cars) {
        for (int i = X; i >= 0; i--) {
            int j = min(X, i + p);
            dp[j] = min(dp[j], dp[i] + v);
        }
    }

    cout << (dp[X] == INF ? -1 : dp[X]) << "\n";

    return 0;
}
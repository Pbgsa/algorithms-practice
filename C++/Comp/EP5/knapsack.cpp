#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N, W;
    cin >> N >> W;

    vector<pair<int, int>> itens(N);
    for (int i = 0; i < N; i++) {
        cin >> itens[i].first >> itens[i].second;
    }

    vector<ll> dp(W+1, 0);
    
    for (int i = 0; i < N; i++) {
        for (int weight = W; weight >= itens[i].first; weight--) {
            dp[weight] = max(dp[weight], dp[weight - itens[i].first] + itens[i].second);
        }
    }

    cout << *max_element(dp.begin(), dp.end()) << "\n";

    return 0;
}
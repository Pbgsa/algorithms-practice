#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N, K;
    cin >> N >> K;

    vector<int> heights(N);
    for (int i = 0; i < N; i++) {
        cin >> heights[i];
    }

    vector<int> dp(N, INT_MAX);
    dp[0] = 0;

    for (int i = 0; i < N; i++) {
        for (int j = 0; j <= K; j++) {
            if (i - j >= 0) {
                dp[i] = min(dp[i], dp[i-j] + abs(heights[i] - heights[i-j]));
            }
        }
    }

    cout << dp[N - 1] << "\n";

    return 0;
}
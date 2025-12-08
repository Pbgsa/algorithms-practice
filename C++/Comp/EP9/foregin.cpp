#include <bits/stdc++.h>
using namespace std;

using ll = long long;

static ll dp[2005][2005];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    ll n, m, a, b, c;
    cin >> n >> m >> a >> b >> c;

    string s, t;
    cin >> s >> t;

    dp[0][0] = 0;
    for (int i = 1; i <= n; i++) {
        dp[i][0] = dp[i-1][0] + b;
    }

    for (int j = 1; j <= m; j++) {
        dp[0][j] = dp[0][j-1] + a;
    }

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            ll cost_mod = c;
            if (s[i-1] == t[j-1]) {
                cost_mod = 0;
            }

            dp[i][j] = min({
                dp[i-1][j] + b,          
                dp[i][j-1] + a,          
                dp[i-1][j-1] + cost_mod  
            });
        }
    }

    cout << dp[n][m] << "\n";
    return 0;
}

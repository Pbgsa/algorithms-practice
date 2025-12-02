#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, a, b;
    cin >> n >> a >> b;

    vector<long double> dp(6*n + 1), nextdp(6*n + 1);
    dp[0] = 1;

    for (int i = 1; i <= n; i++) {
        fill(nextdp.begin(), nextdp.end(), 0);
        for (int s = 0; s <= 6*(i-1); s++) {
            if (dp[s] == 0) continue;
            for (int face = 1; face <= 6; face++) {
                nextdp[s + face] += dp[s];
            }
        }
        dp = nextdp;
    }

    long double favorable = 0;
    for (int s = a; s <= b; s++) {
        if (s >= 0 && s <= 6*n) favorable += dp[s];
    }

    long double total = pow((long double)6, n);

    long double ans = favorable / total;

    cout << fixed << setprecision(6) << ans << "\n";
}

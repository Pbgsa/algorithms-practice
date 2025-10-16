#include <bits/stdc++.h>
using namespace std;

#define pb push_back
#define all(v) v.begin(), v.end()
using ll = long long;

bool canAppear(const vector<ll>& a, ll n, ll x, ll total) {
    ll sum = total + x;
    double limit = (double)sum / (2.0 * n);
    int unhappy = 0;
    for (ll val : a) {
        if (val < limit) {
            unhappy++;
        }
    }
    return unhappy > n / 2;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;

    while (t--)
    {
        ll n;
        cin >> n;
        vector<ll> pop_wealth(n);
        for (int i = 0; i < n; i++) {
            cin >> pop_wealth[i];
        }

        if (n <= 2) {
            cout << -1 << '\n';
            continue;
        }

        ll total = accumulate(all(pop_wealth), 0LL);
        ll max_val = *max_element(all(pop_wealth));

        
        if (canAppear(pop_wealth, n, 0, total)) {
            cout << 0 << '\n';
            continue;
        }

        ll lo = 0, hi = 1e14, ans = -1;
        while (lo <= hi) {
            ll mid = (lo + hi) / 2;
            if (canAppear(pop_wealth, n, mid, total)) {
                ans = mid;
                hi = mid - 1;
            } else {
                lo = mid + 1;
            }
        }

        cout << ans << "\n";
    }
    

    return 0;
}
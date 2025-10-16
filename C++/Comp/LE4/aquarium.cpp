#include <bits/stdc++.h>
using namespace std;

#define pb push_back
#define all(v) v.begin(), v.end()
using ll = long long;

void maxWaterLevel(const vector<ll>& a, ll x) {
    int n = a.size();
    ll low = a[0];
    ll high = a[0] + x;
    ll best_level = low;

    while (low <= high) {
        ll mid = low + (high - low) / 2;
        ll total_water_needed = 0;

        for (ll height : a) {
            if (height < mid) {
                total_water_needed += (mid - height);
            }
        }

        if (total_water_needed <= x) {
            best_level = mid;
            low = mid + 1;
        } else {
            high = mid - 1;
        }
    }

    cout << best_level << "\n";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    while(t--) {
        ll n, x;
        cin >> n >> x;
        vector<ll> a(n);
        for (int i = 0; i < n; i++) {
            cin >> a[i];
        }

        sort(all(a));

        maxWaterLevel(a, x);
    }

    return 0;
}
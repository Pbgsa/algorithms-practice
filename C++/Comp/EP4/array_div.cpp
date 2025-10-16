#include <bits/stdc++.h>
using namespace std;

#define all(v) v.begin(), v.end()
using ll = long long;

bool canDivide (vector<ll>& a, ll limit, int k) {
    int parts = 1;
    ll curr_sum = 0;

    for (ll x : a) {
        if (curr_sum + x > limit) {
            parts++;
            curr_sum = x;
        } else {
            curr_sum += x;
        }
    }

    return parts <= k;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, k;
    cin >> n >> k;
    vector<ll> array(n);
    for (int i = 0; i < n; i++) {
        cin >> array[i];
    }

    ll low = *max_element(all(array));
    ll high = accumulate(all(array), 0LL);
    ll ans = high;

    while (low <= high) {
        ll mid = (low + high) / 2;
        if (canDivide(array, mid, k)) {
            ans = mid;
            high = mid - 1;
        } else {
            low = mid + 1;
        }
    }

    cout << ans << "\n";    

    return 0;
}
#include <bits/stdc++.h>
using namespace std;

using ll = long long;

const ll MOD = 1000000007LL;

ll modFromString(const string &s, ll mod) {
    ll r = 0;
    for (char c : s) {
        r = (r * 10 + (c - '0')) % mod;
    }
    return r;
}

ll modPow(ll a, ll e, ll mod) {
    ll r = 1;
    while (e > 0) {
        if (e & 1) r = (r * a) % mod;
        a = (a * a) % mod;
        e >>= 1;
    }
    return r;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    string x, y;
    char op;
    if (!(cin >> x >> op >> y)) return 0;

    if (op == '+') {
        ll a = modFromString(x, MOD);
        ll b = modFromString(y, MOD);
        ll ans = (a + b) % MOD;
        cout << ans << '\n';
    } else if (op == '-') {
        ll a = modFromString(x, MOD);
        ll b = modFromString(y, MOD);
        ll ans = (a - b) % MOD;
        if (ans < 0) ans += MOD;
        cout << ans << '\n';
    } else if (op == '*') {
        ll a = modFromString(x, MOD);
        ll b = modFromString(y, MOD);
        ll ans = (a * b) % MOD;
        cout << ans << '\n';
    } else if (op == '^') {
        ll a = modFromString(x, MOD);
        if (a == 0) {
            cout << 0 << '\n'; 
            return 0;
        }
        ll e = modFromString(y, MOD - 1);
        ll ans = modPow(a, e, MOD);
        cout << ans << '\n';
    }

    return 0;
}

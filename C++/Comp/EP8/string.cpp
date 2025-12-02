#include <bits/stdc++.h>
using namespace std;

using ll = long long;

const int MOD = (1e9 + 7);
const int MAX_N = 1e6;

ll fact[MAX_N + 1], invfact[MAX_N + 1];

ll modpow(ll a, ll e) {
    ll r = 1;
    while (e){
        if (e & 1) {
            r = r * a % MOD;
        }
        a = a * a % MOD;
        e >>= 1;
    }
    return r;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    string s;
    cin >> s;

    int n = s.size();

    fact[0] = 1;
    for (int i = 1; i <= n; i++) {
        fact[i] = fact[i - 1] * i % MOD;
    }

    invfact[n] = modpow(fact[n], MOD - 2);
    for (int i = n; i > 0; i--) {
        invfact[i-1] = invfact[i] * i % MOD;
    }

    vector<int> freq(26, 0);
    for (auto c : s) {
        freq[c - 'a']++;
    }

    ll ans = fact[n];


    for (int f : freq) {
        if (f > 1) {
            ans = ans * invfact[f] % MOD;
        }
    }

    cout << ans << "\n";

    return 0;
}
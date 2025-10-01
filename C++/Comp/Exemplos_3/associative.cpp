#include <bits/stdc++.h>
using namespace std;

#define pb push_back
#define all(v) v.begin(), v.end()
using ll = long long;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int q;
    cin >> q;
    map<ll, ll> m;
    for (int i = 0; i < q; i++) {
        int op;
        cin >> op;
        if (op == 0) {
            ll k, v;
            cin >> k;
            cin >> v;

            m[k] = v;
        } else {
            ll k;
            cin >> k;

            if (m.count(k)) {
                cout << m[k] << '\n';
            } else {
                cout << 0 << '\n';
            }
        }
    }

}
#include <bits/stdc++.h>
using namespace std;

#define pb push_back
#define all(v) v.begin(), v.end()
using ll = long long;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;

    while (t--) {
        int n;
        cin >> n;

        map<string, int> attributes;
        ll total_comb = 1;
        for (int i = 0; i < n; i++) {
            string obj, cat;

            cin >> obj >> cat;

            attributes[cat]++;
        }

        for (auto [cat, cnt]:attributes) {
            total_comb *= (cnt + 1);
        }

        cout << total_comb - 1 << '\n';
    }
}
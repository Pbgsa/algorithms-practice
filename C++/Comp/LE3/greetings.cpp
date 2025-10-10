#include <bits/stdc++.h>
using namespace std;

struct Fenwick {
    vector<int> bit;
    int n;
    Fenwick(int n) : n(n) { bit.assign(n + 1, 0); }
    void update(int idx, int val) {
        for (; idx <= n; idx += idx & -idx)
            bit[idx] += val;
    }
    int query(int idx) {
        int sum = 0;
        for (; idx > 0; idx -= idx & -idx)
            sum += bit[idx];
        return sum;
    }
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<pair<int, int>> people(n);
        for (int i = 0; i < n; ++i) {
            cin >> people[i].first >> people[i].second;
        }

        sort(people.begin(), people.end());

        vector<int> b;
        for (auto &p : people) b.push_back(p.second);
        
        vector<int> vals = b;
        sort(vals.begin(), vals.end());
        vals.erase(unique(vals.begin(), vals.end()), vals.end());
        for (auto &x : b) {
            x = lower_bound(vals.begin(), vals.end(), x) - vals.begin() + 1;
        }

        Fenwick ft(n);
        long long ans = 0;
        for (int i = n - 1; i >= 0; --i) {
            ans += ft.query(b[i] - 1);
            ft.update(b[i], 1);
        }
        
        cout << ans << "\n";
    }
    return 0;
}

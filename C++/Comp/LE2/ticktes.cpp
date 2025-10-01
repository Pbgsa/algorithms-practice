#include <bits/stdc++.h>
using namespace std;

#define pb push_back
#define all(v) v.begin(), v.end()
using ll = long long;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m;
    cin >> n >> m;
    multiset<int> tickets;
    for (int i = 0; i < n; i++) {
        int price;
        cin >> price;
        tickets.insert(price);
    }

    for (int i = 0; i < m; i++) {
        int payment;
        cin >> payment;

        auto it = tickets.upper_bound(payment);

        if (it == tickets.begin()) {
            cout << -1 << '\n';
        } else {
            it--;
            cout << *it << '\n';
            tickets.erase(it);
        }
    }
}
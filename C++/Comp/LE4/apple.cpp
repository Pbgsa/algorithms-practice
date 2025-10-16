#include <bits/stdc++.h>
using namespace std;

#define pb push_back
#define all(v) v.begin(), v.end()
using ll = long long;

void divideMinimal(int n, vector<ll>& w) {
    ll total_weight = accumulate(all(w), 0LL);
    ll min_difference = LLONG_MAX;
    // vector<ll> best_group1, best_group2;
    int total_combinations = 1 << n;

    for (int mask = 0; mask < total_combinations; mask++) {
        ll group1_weight = 0;
        // vector<ll> group1, group2;

        for (int i = 0; i < n; i++) {
            if (mask & (1 << i)) {
                group1_weight += w[i];
                // group1.pb(w[i]);
            } 
            // else {
            //     group2.pb(w[i]);
            // }
        }

        ll group2_weight = total_weight - group1_weight;
        ll difference = std::abs(group1_weight - group2_weight);

        if (difference < min_difference) {
            min_difference = difference;
            // best_group1 = group1;
            // best_group2 = group2;
        }
    }

    // for (ll weight : best_group1) {
    //     cout << weight << " ";
    // }
    // cout << "\n";
    // for (ll weight : best_group2) {
    //     cout << weight << " ";
    // }
    cout << min_difference << "\n";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;
    vector<ll> w(n);
    for (int i = 0; i < n; i++){
        cin >> w[i];
    }

    sort(all(w));

    divideMinimal(n, w);

    return 0;
}
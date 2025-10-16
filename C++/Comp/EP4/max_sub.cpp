#include <bits/stdc++.h>
using namespace std;

#define pb push_back
#define all(v) v.begin(), v.end()
using ll = long long;

vector<ll> generateSums(vector<ll>& arr, int m) {
    vector<ll> res;
    int n = arr.size();
    for (int mask = 0; mask < (1 << n); mask++) {
        ll sum = 0;
        for (int i = 0; i < n; i++) {
            if (mask & (1 << i)) {
                sum = (sum + arr[i]) % m;
            }
        }
        res.pb(sum);
    }

    return res;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m;
    cin >> n >> m;

    vector<ll> arr(n);
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    vector<ll> res = generateSums(arr, m);

    int max_val = *max_element(all(res));

    cout << max_val << '\n';

    return 0;
}
#include <bits/stdc++.h>
using namespace std;

#define pb push_back
#define all(v) v.begin(), v.end()
using ll = long long;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, target_sum;
    cin >> n >> target_sum;

    map<int, int> m;
    for (int i = 1; i <= n; i++) {
        int num;
        cin >> num;

        if (m.count(target_sum-num)){
            cout << m[target_sum-num] << ' ' << i << '\n';
            return 0;
        } else {
            m[num] = i;
        }
    }
    cout << "IMPOSSIBLE" << '\n';
    return 0;
}
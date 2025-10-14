#include <bits/stdc++.h>
using namespace std;

#define pb push_back
#define all(v) v.begin(), v.end()
using ll = long long;

void numValidPermutations(int n, const vector<tuple<int, int, int>>& constraints) {
    int valid_count = 0;
    vector<int> perm(n);
    iota(perm.begin(), perm.end(), 0);

    do {
        bool valid = true;
        for (const auto& [a, b, c] : constraints) {
            int dist = abs(perm[a] - perm[b]);

            if ((c < 0 && dist < abs(c)) || (c > 0 && dist > c)) {
                valid = false;
                break;
            }
        }
        if (valid) valid_count++;
    } while (next_permutation(perm.begin(), perm.end()));
    cout << valid_count << "\n";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    while (1) {
        int n, m;
        cin >> n >> m;

        if (m == 0 && n == 0) {
            break;
        }

        vector<tuple<int, int, int>> constraints;
        for (int i = 0; i < m; i++) {
            int a, b, c;
            cin >> a >> b >> c;
            constraints.emplace_back(a, b, c);
        }

        numValidPermutations(n, constraints);
    }

    return 0;
}
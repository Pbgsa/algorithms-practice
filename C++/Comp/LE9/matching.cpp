#include <bits/stdc++.h>
using namespace std;
using ll = long long;

vector<int> buildLPS(const string &p) {
    int m = p.size();
    vector<int> lps(m, 0);
    int j = 0;
    for (int i = 1; i < m; i++) {
        while (j > 0 && p[i] != p[j])
            j = lps[j-1];
        if (p[i] == p[j])
            j++;
        lps[i] = j;
    }
    return lps;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    string s, p;
    cin >> s >> p;

    int n = s.size(), m = p.size();
    vector<int> lps = buildLPS(p);

    int j = 0;
    ll count = 0;

    for (int i = 0; i < n; i++) {
        while (j > 0 && s[i] != p[j])
            j = lps[j-1];

        if (s[i] == p[j])
            j++;

        if (j == m) {
            count++;
            j = lps[j-1];
        }
    }

    cout << count << "\n";
}

#include <bits/stdc++.h>
using namespace std;

const int MAX_X = 1e6;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    vector<int> divs(MAX_X + 1, 0);

    for (int i = 1; i <= MAX_X; i++) {
        for (int j = i; j <= MAX_X; j += i) {
            divs[j]++;
        }
    }

    int n;
    cin >> n;
    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;
        cout << divs[x] << '\n';
    }

    return 0;
}
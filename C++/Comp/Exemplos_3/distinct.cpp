#include <bits/stdc++.h>
using namespace std;

#define pb push_back
#define all(v) v.begin(), v.end()
using ll = long long;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;
    set<int> numbers;
    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;
        numbers.insert(x);
    }

    cout << numbers.size() << '\n';
}
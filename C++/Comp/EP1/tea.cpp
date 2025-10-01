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

        queue<int> arr, leav;
        for (int i = 0; i < n; i++) {
            int in, out;
            cin >> in >> out;

            arr.emplace(in);
            leav.emplace(out);
        }

        int t = 1;
        while(!arr.empty()) {
            if (t < arr.front()) {
                t = arr.front();
            }

            if (t <= leav.front()) {
                arr.pop();
                leav.pop();
                cout << t << ' ';
                
                t++;
            } else {
                arr.pop();
                leav.pop();
                cout << 0 << ' ';
            }
        }

        cout << '\n';
    }

}
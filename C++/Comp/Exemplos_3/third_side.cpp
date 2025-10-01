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

    for (int i = 0; i < t; i++) {
        int n;
        cin >> n;

        priority_queue<int> pq;

        for (int j = 0; j < n; j++) {
            int a;
            cin >> a;
        
            pq.push(a);
        }

        while (pq.size() > 1) {
            int a, b;

            a = pq.top();
            pq.pop();

            b = pq.top();
            pq.pop();

            int min = a + b - 1;

            pq.push(min);
        }

        cout << pq.top() << '\n';
    }
}
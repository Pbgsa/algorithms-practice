#include <bits/stdc++.h>
using namespace std;

const int MAX_P = 6000000;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    vector<int> primes;
    vector<char> is_prime(MAX_P, true);
    is_prime[0] = is_prime[1] = false;
    for (int i = 2; i < MAX_P; ++i) {
        if (!is_prime[i]){
            continue;
        } 
        primes.push_back(i);
        if ((long long)i * i < MAX_P)
            for (int j = i * 2; j < MAX_P; j += i) {
                is_prime[j] = false;
            }
    }

    int t;
    if (!(cin >> t)) {
        return 0;
    }
    while (t--) {
        int n;
        cin >> n;
        vector<long long> a(n);
        for (int i = 0; i < n; ++i) cin >> a[i];

        sort(a.begin(), a.end(), greater<long long>());

        long long suma = 0, sump = 0;
        int best_k = 0;
        for (int i = 0; i < n; ++i) {
            suma += a[i];
            sump += primes[i];
            if (suma >= sump) best_k = i + 1;
        }

        cout << (n - best_k) << "\n";
    }
    return 0;
}

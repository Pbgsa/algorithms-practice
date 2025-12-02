#include <bits/stdc++.h>
using namespace std;

const int N = 10000000;

vector<bool> isPrime(N + 1, true);
vector<int> count_primes(N + 1);

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    isPrime[0] = isPrime[1] = false;
    for (int i = 2; i * 1LL * i <= N; i++) {
        if (isPrime[i]) {
            for (int j = i * i; j <= N; j += i)
                isPrime[j] = false;
        }
    }

    int last_count_prime = 0;
    for (int i = 1; i <= N; i++) {
        if (isPrime[i]) {
            count_primes[i] = last_count_prime++;
            // cout << "Prime " << i << ": " <<  count_primes[i] << '\n';
        }
    }

    int q;
    cin >> q;

    while (q--) {
        int n;
        cin >> n;

        // cout << "For " << n << ": ";

        bool isBeatiful = true;
        while (n > 1) {
            if (!isPrime[n]) {
                isBeatiful = false;
                break;
            }
            n = count_primes[n];
            // cout << n << " ";
        }

        if (n == 1) {
            isBeatiful = false;
        }

        cout << (isBeatiful ? "yEs\n" : "NO\n");
    }

    return 0;
}

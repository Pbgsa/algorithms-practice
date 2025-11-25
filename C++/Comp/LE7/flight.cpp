#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N;
    cin >> N;

    vector<vector<ll>> C(N, vector<ll>(N));
    for (int i = 0; i < N; i++)
        for (int j = 0; j < N; j++)
            cin >> C[i][j];

    for (int k = 0; k < N; k++)
        for (int i = 0; i < N; i++)
            for (int j = 0; j < N; j++)
                if (C[i][j] > C[i][k] + C[k][j]) {
                    cout << -1 << "\n";
                    return 0;
                }

    int redundant = 0;

    for (int i = 0; i < N; i++) {
        for (int j = i+1; j < N; j++) {

            bool needed = true;

            for (int k = 0; k < N; k++) {
                if (k != i && k != j) {
                    if (C[i][j] == C[i][k] + C[k][j]) {
                        needed = false;
                        break;
                    }
                }
            }

            if (!needed) redundant++;
        }
    }

    cout << redundant << "\n";
    return 0;
}

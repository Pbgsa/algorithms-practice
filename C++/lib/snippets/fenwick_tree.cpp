// =====================================================
// Fenwick Tree / BIT (Binary Indexed Tree)
// =====================================================
#include <bits/stdc++.h>
using namespace std;

struct Fenwick {
    int n;
    vector<long long> bit;

    Fenwick(int n) {
        this->n = n;
        bit.assign(n+1, 0);
    }

    void update(int idx, long long val) {
        for (; idx <= n; idx += idx & -idx)
            bit[idx] += val;
    }

    long long query(int idx) {
        long long sum = 0;
        for (; idx > 0; idx -= idx & -idx)
            sum += bit[idx];
        return sum;
    }

    long long range_query(int l, int r) {
        return query(r) - query(l-1);
    }
};

// ====================== EXEMPLO ======================
// Fenwick fw(10);
// fw.update(3, 5);   // adiciona +5 na posição 3
// fw.update(5, 2);   // adiciona +2 na posição 5
// cout << fw.query(5);        // soma [1..5] = 7
// cout << fw.range_query(3,5); // soma [3..5] = 7

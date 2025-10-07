// =====================================================
// DSU (Disjoint Set Union) / Union-Find
// =====================================================
#include <bits/stdc++.h>
using namespace std;

struct DSU {
    vector<int> parent, rank;

    DSU(int n) {
        parent.resize(n+1);
        rank.assign(n+1, 0);
        for (int i = 0; i <= n; i++) parent[i] = i;
    }

    int find(int x) {
        if (parent[x] == x) return x;
        return parent[x] = find(parent[x]); // Path compression
    }

    void unite(int a, int b) {
        a = find(a);
        b = find(b);
        if (a != b) {
            if (rank[a] < rank[b]) swap(a, b);
            parent[b] = a;
            if (rank[a] == rank[b]) rank[a]++;
        }
    }

    bool same(int a, int b) {
        return find(a) == find(b);
    }
};

// ====================== EXEMPLO ======================
// DSU dsu(10);
// dsu.unite(1, 2);
// dsu.unite(2, 3);
// cout << dsu.same(1, 3); // true

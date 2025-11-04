#include <bits/stdc++.h>
using namespace std;

#define all(v) v.begin(), v.end()
using ll = long long;

struct Edge {
    int u, v;
    ll w;
    bool operator<(const Edge& other) const {
        return w < other.w;
    }
};

struct DSU {
    vector<int> parent, rnk;
    DSU(int n) {
        parent.resize(n+1);
        rnk.assign(n+1, 0);
        iota(all(parent), 0);
    }

    int find(int v) {
        if (v == parent[v]) return v;
        return parent[v] = find(parent[v]);
    }

    bool unite(int a, int b) {
        a = find(a); b = find(b);
        if (a == b) return false;
        if (rnk[a] < rnk[b]) swap(a, b);
        parent[b] = a;
        if (rnk[a] == rnk[b]) rnk[a]++;
        return true;
    }
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m;
    cin >> n >> m;

    vector<Edge> edges(m);
    for (int i = 0; i < m; i++) {
        cin >> edges[i].u >> edges[i].v >> edges[i].w;
    }

    sort(all(edges));
    DSU dsu(n);

    ll total = 0;
    int cnt = 0;

    for (auto &e : edges) {
        if (dsu.unite(e.u, e.v)) {
            total += e.w;
            cnt++;
        }
    }

    if (cnt == n - 1)
        cout << total << "\n";
    else
        cout << "IMPOSSIBLE\n";

    return 0;
}
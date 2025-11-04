#include <bits/stdc++.h>
using namespace std;

#define pb push_back
#define all(v) v.begin(), v.end()
using ll = long long;

struct Edge {
    int u, v, w;
    bool operator<(const Edge& other) const {
        return w < other.w;
    }
};

struct DSU {
    vector<int> p, r;

    DSU(int n) {
        p.resize(n);
        r.assign(n, 0);
        iota(p.begin(), p.end(), 0);
    }

    int find(int v) {
        if (p[v] == v) return v;
        return p[v] = find(p[v]);
    }

    bool unite(int a, int b) {
        a = find(a); b = find(b);
        if (a == b) return false;
        if (r[a] < r[b]) swap(a, b);
        p[b] = a;
        if (r[a] == r[b]) r[a]++;
        return true;
    }
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    while (true) {
        int n, m;
        cin >> n >> m;
    
        if (n == 0 && m == 0) {
            break;
        }
    
        vector<Edge> edges(m);
        for (int i = 0; i < m; i++) {
            cin >> edges[i].u >> edges[i].v >> edges[i].w;
        }

        sort(all(edges));
        DSU dsu(n);

        int components = n;
        int maxEdge = -1;

        for (auto& e : edges) {
            if (dsu.unite(e.u, e.v)) {
                maxEdge = max(maxEdge, e.w);
                components--;
            }
        }

        if (components == 1) {
            cout << maxEdge << '\n';
        } else {
            cout << "IMPOSSIBLE" << '\n';
        }
    }

    return 0;
}
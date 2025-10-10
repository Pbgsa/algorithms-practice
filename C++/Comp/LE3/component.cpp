#include <bits/stdc++.h>
using namespace std;

struct DSU {
    vector<int> parent, sz;

    DSU(int n) {
        parent.resize(n+1);
        sz.assign(n+1, 1);
        iota(parent.begin(), parent.end(), 0);
    }

    int find(int x) {
        if (parent[x] == x) return x;
        return parent[x] = find(parent[x]);
    }

    bool unite(int a, int b) {
        a = find(a);
        b = find(b);
        if (a == b) return false;
        if (sz[a] < sz[b]) swap(a, b);
        parent[b] = a;
        sz[a] += sz[b];
        return true;
    }

    int size(int x) {
        return sz[find(x)];
    }
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m;
    cin >> n >> m;
    DSU dsu(n);

    int num_components = n;
    int largest_component = 1;

    for (int i = 0; i < m; i++) {
        int a, b;
        cin >> a >> b;

        if (dsu.unite(a, b)) {
            num_components--;
            largest_component = max(largest_component, dsu.size(a));
        }

        cout << num_components << " " << largest_component << "\n";
    }

    return 0;
}

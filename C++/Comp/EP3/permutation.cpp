#include <bits/stdc++.h>
using namespace std;

struct DSU {
    vector<int> parent;
    vector<int> size;
    DSU(int n) {
        parent.resize(n + 1);
        size.assign(n + 1, 1);
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
        if (size[a] < size[b]) swap(a, b);
        parent[b] = a;
        size[a] += size[b];
        return true;
    }
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<int> p(n + 1), d(n + 1);
        for (int i = 1; i <= n; i++) cin >> p[i];
        for (int i = 1; i <= n; i++) cin >> d[i];

        DSU dsu(n);
        vector<bool> active(n + 1, false);
        vector<int> ans(n + 1);
        int components = 0;

        // Processa de trás pra frente
        for (int i = n; i >= 1; i--) {
            int x = d[i];
            active[x] = true;
            components++;  // novo nó isolado

            int y = p[x];
            if (active[y]) {
                if (dsu.unite(x, y)) components--;
            }
            ans[i] = components;
        }

        // Saída na ordem correta (após cada deleção)
        for (int i = 1; i <= n; i++)
            cout << ans[i] << " ";
        cout << "\n";
    }
}

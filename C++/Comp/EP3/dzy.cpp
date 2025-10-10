#include <bits/stdc++.h>
using namespace std;

#define pb push_back
#define all(v) v.begin(), v.end()
using ll = long long;

struct DSU {
    vector<int> parent, rank;

    DSU(int n) {
        parent.resize(n+1);
        rank.assign(n+1, 0);
        for (int i = 0; i <= n; i++) parent[i] = i;
    }

    int find(int x) {
        if (parent[x] == x) return x;
        return parent[x] = find(parent[x]);
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

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m;
    cin >> n >> m;
    
    DSU dsu(n);
    for (int i = 0; i < m; i++) {
        int a, b;
        cin >> a >> b;
        
        dsu.unite(a, b);
    }
    
    vector<int> comp_size(n+1, 0);
    for (int i = 1; i <= n; i++) {
        comp_size[dsu.find(i)]++;
    }
    
    ll danger = 1;
    for (int s : comp_size) {
        if (s > 0) {
            danger *= (1LL << (s - 1));
        }
    }

    cout << danger << '\n';
}
#include <bits/stdc++.h>
using namespace std;

#define pb push_back
#define all(v) v.begin(), v.end()

const int MAX_N = 1e5 + 5;
vector<int> adj[MAX_N];
vector<int> parent(MAX_N, -1);
vector<int> visited(MAX_N, 0);

int start = -1, endd = -1;

bool dfs(int u, int p) {
    visited[u] = 1;
    for (int v : adj[u]) {
        if (v == p) {
            continue;
        }
        if (visited[v]) {
            start = v;
            endd = u;
            return true;
        }
        parent[v] = u;
        if (dfs(v, u)) {
            return true;
        }
    }
    return false;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m;
    cin >> n >> m;
    for (int i = 0; i < m; i++) {
        int a, b; cin >> a >> b;
        adj[a].pb(b);
        adj[b].pb(a);
    }

    for (int i = 1; i <= n; i++) {
        if (!visited[i] && dfs(i, -1))
            break;
    }

    if (start == -1) {
        cout << "IMPOSSIBLE\n";
        return 0;
    }

    vector<int> cycle;
    cycle.pb(start);
    for (int v = endd; v != start; v = parent[v]) {
        cycle.pb(v);
    }
    cycle.pb(start);

    reverse(all(cycle));

    cout << cycle.size() << "\n";
    for (int v : cycle) {
        cout << v << " ";
    }
    cout << "\n";

    return 0;
}

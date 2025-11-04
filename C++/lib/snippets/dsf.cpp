#include <bits/stdc++.h>
using namespace std;

// Uso: detectar ciclos, componentes conexas, ordenação topológica.

vector<vector<int>> adj;
vector<bool> visited;

void dfs(int u) {
    visited[u] = true;
    cout << u << " ";
    for (int v : adj[u]) {
        if (!visited[v])
            dfs(v);
    }
}

int main() {
    int n, m; cin >> n >> m;
    adj.assign(n, {});
    for (int i = 0; i < m; i++) {
        int u, v; cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    visited.assign(n, false);
    cout << "DFS traversal: ";
    dfs(0);
}

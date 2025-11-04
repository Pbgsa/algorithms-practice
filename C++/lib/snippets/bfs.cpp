#include <bits/stdc++.h>
using namespace std;

// Uso: menor caminho em grafo não ponderado / travessia por camadas.

const int INF = 1e9;
vector<vector<int>> adj;  // lista de adjacência
vector<int> dist;         // distâncias da fonte

void bfs(int start) {
    queue<int> q;
    dist.assign(adj.size(), INF);
    dist[start] = 0;
    q.push(start);

    while (!q.empty()) {
        int u = q.front(); q.pop();
        for (int v : adj[u]) {
            if (dist[v] == INF) {
                dist[v] = dist[u] + 1;
                q.push(v);
            }
        }
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
    bfs(0);
    for (int i = 0; i < n; i++)
        cout << "dist[" << i << "] = " << dist[i] << "\n";
}
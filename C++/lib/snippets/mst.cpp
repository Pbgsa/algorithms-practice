#include <bits/stdc++.h>
using namespace std;

// Kruskal’s Algorithm
// Uso: conectar todos os vértices com custo mínimo.
// Estrutura: usa DSU (Disjoint Set Union).

struct Edge {
    int u, v, w;
    bool operator<(const Edge& other) const {
        return w < other.w;
    }
};

vector<int> parent, rnk;

int find_set(int v) {
    if (v == parent[v]) return v;
    return parent[v] = find_set(parent[v]);
}

bool union_sets(int a, int b) {
    a = find_set(a);
    b = find_set(b);
    if (a == b) return false;
    if (rnk[a] < rnk[b]) swap(a, b);
    parent[b] = a;
    if (rnk[a] == rnk[b]) rnk[a]++;
    return true;
}

int kruskal(int n, vector<Edge>& edges) {
    sort(edges.begin(), edges.end());
    parent.resize(n);
    rnk.assign(n, 0);
    iota(parent.begin(), parent.end(), 0);

    int total = 0;
    for (auto& e : edges) {
        if (union_sets(e.u, e.v))
            total += e.w;
    }
    return total;
}

int main() {
    int n, m; cin >> n >> m;
    vector<Edge> edges(m);
    for (int i = 0; i < m; i++)
        cin >> edges[i].u >> edges[i].v >> edges[i].w;
    cout << "MST cost = " << kruskal(n, edges) << "\n";
}

// Prim’s Algorithm
// Uso: alternativa ao Kruskal, ideal para grafos densos.
// Estrutura: usa priority_queue (min-heap).

typedef pair<int,int> ii;
vector<vector<ii>> adj; // {vizinho, peso}

int prim(int start) {
    int n = adj.size();
    vector<int> dist(n, 1e9);
    vector<bool> inMST(n, false);
    priority_queue<ii, vector<ii>, greater<ii>> pq;
    dist[start] = 0;
    pq.push({0, start});

    int total = 0;
    while (!pq.empty()) {
        auto [d, u] = pq.top(); pq.pop();
        if (inMST[u]) continue;
        inMST[u] = true;
        total += d;

        for (auto [v, w] : adj[u]) {
            if (!inMST[v] && w < dist[v]) {
                dist[v] = w;
                pq.push({w, v});
            }
        }
    }
    return total;
}

int main() {
    int n, m; cin >> n >> m;
    adj.assign(n, {});
    for (int i = 0; i < m; i++) {
        int u, v, w; cin >> u >> v >> w;
        adj[u].push_back({v, w});
        adj[v].push_back({u, w});
    }
    cout << "MST cost = " << prim(0) << "\n";
}

// Topological Sort
// Uso: ordenação de tarefas / dependências.
// Só funciona em grafos dirigidos acíclicos (DAGs).

vector<vector<int>> adj;
vector<int> indeg;

vector<int> topo_sort(int n) {
    queue<int> q;
    vector<int> order;

    for (int i = 0; i < n; i++)
        if (indeg[i] == 0)
            q.push(i);

    while (!q.empty()) {
        int u = q.front(); q.pop();
        order.push_back(u);
        for (int v : adj[u]) {
            indeg[v]--;
            if (indeg[v] == 0)
                q.push(v);
        }
    }
    return order;
}

int main() {
    int n, m; cin >> n >> m;
    adj.assign(n, {});
    indeg.assign(n, 0);
    for (int i = 0; i < m; i++) {
        int u, v; cin >> u >> v;
        adj[u].push_back(v);
        indeg[v]++;
    }

    vector<int> order = topo_sort(n);
    cout << "Topological order: ";
    for (int u : order) cout << u << " ";
}

// DSU (Disjoint Set Union)
// Uso: estrutura base para Kruskal e detecção de componentes.

struct DSU {
    vector<int> parent, rnk;
    DSU(int n) {
        parent.resize(n);
        rnk.assign(n, 0);
        iota(parent.begin(), parent.end(), 0);
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

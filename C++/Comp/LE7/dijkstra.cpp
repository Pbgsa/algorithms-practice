#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define INF 1e18

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    ll n, m;
    cin >> n >> m;

    vector<vector<pair<ll,ll>>> adj(n+1);
    for (int i = 0; i < m; i++) {
        ll a, b, w;
        cin >> a >> b >> w;
        adj[a].push_back({b, w});
        adj[b].push_back({a, w});
    }

    vector<ll> dist(n+1, INF), parent(n+1, -1);
    priority_queue<pair<ll,ll>, vector<pair<ll,ll>>, greater<>> pq;

    dist[1] = 0;
    pq.push({0, 1});

    while (!pq.empty()) {
        auto [d, u] = pq.top(); pq.pop();
        if (d != dist[u]) continue;

        for (auto [v, w] : adj[u]) {
            if (dist[v] > dist[u] + w) {
                dist[v] = dist[u] + w;
                parent[v] = u;
                pq.push({dist[v], v});
            }
        }
    }

    if (dist[n] == INF) {
        cout << -1 << "\n";
        return 0;
    }

    vector<ll> path;
    for (ll v = n; v != -1; v = parent[v]) {
        path.push_back(v);
    }

    reverse(path.begin(), path.end());

    for (ll x : path) cout << x << " ";
    cout << "\n";
}

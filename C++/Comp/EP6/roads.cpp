#include <bits/stdc++.h>
using namespace std;

#define pb push_back

vector<vector<int>> adj;
vector<bool> visited;

void dfs(int u) {
    visited[u] = true;
    for (int v : adj[u])
        if (!visited[v])
            dfs(v);
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m;
    cin >> n >> m;
    
    adj.assign(n+1, {});
    visited.assign(n+1, false);

    for (int i = 0; i < m; i++) {
        int a, b;
        cin >> a >> b;

        adj[a].pb(b);
        adj[b].pb(a);
    }

    vector<int> resp;
    for (int i = 1; i <= n; i++) {
        if (!visited[i]) {
            dfs(i);
            resp.pb(i);
        }
    }
    
    cout << resp.size() - 1 << '\n';
    for (int i = 1; i < (int)resp.size(); i++) {
        cout << resp[i -1] << " " << resp[i] << '\n';
    }

    return 0;
}
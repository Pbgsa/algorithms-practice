#include <bits/stdc++.h>
using namespace std;

#define pb push_back

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m;
    cin >> n >> m;
    vector<vector<int>> adj(n + 1);

    for (int i = 0; i < m; i++) {
        int a, b;
        cin >> a >> b;
        adj[a].pb(b);
        adj[b].pb(a);
    }

    vector<int> team(n + 1, 0);

    bool possible = true;

    for (int i = 1; i <= n; i++) {
        if (team[i] == 0) {
            queue<int> q;
            q.push(i);
            team[i] = 1;

            while (!q.empty()) {
                int u = q.front(); 
                q.pop();
                for (int v : adj[u]) {
                    if (team[v] == 0) {
                        team[v] = 3 - team[u];
                        q.push(v);
                    } else if (team[v] == team[u]) {
                        possible = false;
                    }
                }
            }
        }
    }

    if (!possible) {
        cout << "IMPOSSIBLE\n";
    } else {
        for (int i = 1; i <= n; i++){
            cout << team[i] << " ";
        }
        cout << "\n";
    }
}

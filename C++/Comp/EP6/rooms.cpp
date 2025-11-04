#include <bits/stdc++.h>
using namespace std;

int dx[4] = {1, -1, 0, 0};
int dy[4] = {0, 0, 1, -1};

void dfs(vector<string>& grid, vector<vector<bool>>& visited, int n, int m, int x, int y) {
    stack<pair<int, int>> st;
    st.push({x, y});
    visited[x][y] = true;

    while(!st.empty()) {
        auto [cx, cy] = st.top(); 
        st.pop();
        
        for (int dir = 0; dir < 4; dir++) {
            int nx = cx + dx[dir];
            int ny = cy + dy[dir];
            if (nx >= 0 && nx < n && ny >= 0 && ny < m) {
                if (!visited[nx][ny] && grid[nx][ny] == '.') {
                    visited[nx][ny] = true;
                    st.push({nx, ny});
                }
            }
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m;
    cin >> n >> m;
    vector<string> grid(n);
    vector<vector<bool>> visited;
    visited.assign(n, vector<bool>(m, false));

    for (int i = 0; i < n; i++) {
        cin >> grid[i];
    }

    int rooms = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (grid[i][j] == '.' && !visited[i][j]) {
                dfs(grid, visited, n, m, i, j);
                rooms++;
            }
        }
    }

    cout << rooms << '\n';

    return 0;
}
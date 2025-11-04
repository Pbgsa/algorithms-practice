#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int H, W;
    cin >> H >> W;
    vector<string> grid(H);
    for (int i = 0; i < H; i++) cin >> grid[i];

    string snuke = "snuke";
    vector<vector<bool>> vis(H, vector<bool>(W, false));

    int dx[4] = {-1, 1, 0, 0};
    int dy[4] = {0, 0, -1, 1};

    queue<pair<int,int>> q;
    if (grid[0][0] == 's') {
        q.push({0, 0});
        vis[0][0] = true;
    }

    while (!q.empty()) {
        auto [x, y] = q.front(); q.pop();

        if (x == H - 1 && y == W - 1) {
            cout << "Yes\n";
            return 0;
        }

        char next = snuke[(snuke.find(grid[x][y]) + 1) % 5];

        for (int d = 0; d < 4; d++) {
            int nx = x + dx[d], ny = y + dy[d];
            if (nx < 0 || nx >= H || ny < 0 || ny >= W) continue;
            if (vis[nx][ny]) continue;
            if (grid[nx][ny] == next) {
                vis[nx][ny] = true;
                q.push({nx, ny});
            }
        }
    }

    cout << "No\n";

    return 0;
}
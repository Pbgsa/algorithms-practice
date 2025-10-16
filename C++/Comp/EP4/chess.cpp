#include <bits/stdc++.h>
using namespace std;

vector<string> board(8);
bool col[8], diag1[15], diag2[15];
int solutions = 0;

void backtrack(int row) {
    if (row == 8) {
        solutions++;
        return;
    }

    for (int c = 0; c < 8; c++) {
        if (board[row][c] == '*') {
            continue;
        }
        if (col[c] || diag1[row + c] || diag2[row - c + 7]) {
            continue;
        }

        col[c] = diag1[row + c] = diag2[row - c + 7] = true;
        
        backtrack(row + 1);

        col[c] = diag1[row + c] = diag2[row - c + 7] = false;
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    for (int i = 0; i < 8; i++) {
        cin >> board[i];
    }

    backtrack(0);

    cout << solutions << '\n';

    return 0;
}
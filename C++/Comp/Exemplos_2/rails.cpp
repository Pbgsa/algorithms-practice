// A - Rails 
#include <iostream>
#include <algorithm>
#include <vector>
#include <stack>
using namespace std;

void solve(vector<int>& out) {
    int N = out.size();
    vector<int> input(N);
    for (int i = 0; i < N; i++) {
        input[i] = i + 1;
    }

    int pos_out = 0;
    int pos_in = 0;
    stack<int> s;

    while (true) {
        if (!s.empty() && out[pos_out] == s.top()) {
            s.pop();
            pos_out++;
            if (pos_out == N) break;
        } else {
            if (pos_in < N) {
                s.push(input[pos_in++]);
            } else {
                break;
            }
        }
    }

    if (pos_out == N)
        cout << "Yes\n";
    else
        cout << "No\n";
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int N;
    while (true) {
        cin >> N;
        if (N == 0) break;

        int v;
        while (true) {
            cin >> v;
            if (v == 0) break;

            vector<int> out(N);
            out[0] = v;
            for (int i = 1; i < N; i++) {
                cin >> out[i];
            }

            solve(out);
        }
        cout << "\n";
    }
    return 0;
}

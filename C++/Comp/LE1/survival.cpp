#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int N, K, Q;
    cin >> N >> K >> Q;
    vector<int> players_points(N);
    vector<int> correct_player_answers(Q);
    for (int i = 0; i < Q; i++) {
        cin >> correct_player_answers[i];
        players_points[correct_player_answers[i] - 1]++;
    }

    for (int i = 0; i < N; i++) {
        if (players_points[i] + K - Q > 0) {
            cout << "Yes\n";
        } else {
            cout << "No\n";
        }
    }
    return 0;
}
        
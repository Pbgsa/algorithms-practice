#include <bits/stdc++.h>
using namespace std;

#define pb push_back
#define all(v) v.begin(), v.end()
using ll = long long;

void setTracksOfMaxLength(int N, vector<int>& tracks_lengths) {
    int max_length = 0;
    vector<int> best_combination;
    int total_combinations = 1 << tracks_lengths.size();

    for (int mask = 0; mask < total_combinations; mask++) {
        int current_length = 0;
        vector<int> current_combination;

        for (int i = 0; i < tracks_lengths.size(); i++) {
            if (mask & (1 << i)) {
                current_length += tracks_lengths[i];
                current_combination.pb(tracks_lengths[i]);
            }
        }

        if (current_length <= N && current_length > max_length) {
            max_length = current_length;
            best_combination = current_combination;
        }
    }

    for (int length : best_combination) {
        cout << length << " ";
    }
    cout << "sum:" << max_length << "\n";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N;
    while (cin >> N) {
        int tracks;
        cin >> tracks;

        vector<int> tracks_lengths(tracks);
        for (int i = 0; i < tracks; i++)
        {
            cin >> tracks_lengths[i];
        }

        setTracksOfMaxLength(N, tracks_lengths);
    }
    

    return 0;
}
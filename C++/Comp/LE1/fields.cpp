#include <iostream>
#include <vector>
#include <algorithm>
#include <list>
using namespace std;

void optimal_dandelions_cut(long long int all_even_dandelions, list<int>& dandelions_odd, bool state_lawnmower) {
    long long int total_dandelions_cut = 0;
    bool all_even_cut = false;

    // If there are no odd dandelions, we cannot turn on the lawnmower
    if (dandelions_odd.empty()) {
        cout << 0 << "\n";
        return;
    }

    while (!dandelions_odd.empty() || (!all_even_cut && state_lawnmower)) {
        if (!state_lawnmower) {
            if (!dandelions_odd.empty()) {
                total_dandelions_cut += dandelions_odd.back();
                dandelions_odd.pop_back();
                state_lawnmower = true;
            } else {
                // No odd dandelions left to turn on the lawnmower
                break;
            }
        } else {
            if (!all_even_cut) {
                total_dandelions_cut += all_even_dandelions;
                all_even_cut = true;
            } else {
                dandelions_odd.pop_front();
                state_lawnmower = false;
            }
        }
    }

    cout << total_dandelions_cut << "\n";

}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int t; // number of test cases
    cin >> t;
    while (t--) {
        int n; // number of fields
        cin >> n;

        long long int all_even_dandelions = 0; // sum of all even dandelions
        vector<int> dandelions(n); // dandelions in each field
        // List to store even and odd dandelions separately
        list<int> dandelions_odd;

        bool state_lawnmower = false; // lawnmower state, initially off
        for (int i = 0; i < n; i++) {
            cin >> dandelions[i];
            if (dandelions[i] % 2 == 0) {
                all_even_dandelions += dandelions[i];
            } else {
                dandelions_odd.push_back(dandelions[i]);
            }
        }

        // Sort the odd dandelions in ascending order
        dandelions_odd.sort();

        optimal_dandelions_cut(all_even_dandelions, dandelions_odd, state_lawnmower);
    }

    return 0;
}
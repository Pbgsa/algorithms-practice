#include <bits/stdc++.h>
using namespace std;

#define pb push_back
#define all(v) v.begin(), v.end()
using ll = long long;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, target_sum;
    cin >> n >> target_sum;
    multimap<int, int> array;
    for (int i = 0; i < n; i++) {
        int num;
        cin >> num;

        array.insert({num, i+1});
    }

    bool possible = false;
    int ind1, ind2;
    for (auto [num, indice] : array) {
        int target = target_sum - num;

        auto it = array.find(target);

        printf("%d and %d\n", it->first, it->second);

        // if (it != array.end() && it->first != num) {
        //     possible = true;
        //     ind1 = indice;
        //     ind2 = array[target];
        //     break;
        // }
    }

    if (possible) {
        cout << ind2 << ' ' << ind1 << '\n';
    } else {
        cout << "IMPOSSIBLE" << '\n';
    }
}
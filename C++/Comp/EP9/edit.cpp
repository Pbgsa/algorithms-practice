#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    string s, t;
    cin >> s >> t;

    int n = s.size();
    int m = t.size();

    vector<int> prev(m+1), curr(m+1);

    for (int j = 0; j <= m; j++) {
        prev[j] = j;
    } 

    for (int i = 1; i <= n; i++) {
        curr[0] = i;

        for (int j = 1; j <= m; j++) {
            int cost = 1;
            if (s[i-1] == t[j-1]) {
                cost = 0;
            }

            curr[j] = min({
                prev[j] + 1,        
                curr[j-1] + 1,      
                prev[j-1] + cost
            });
        }

        prev = curr;
    }

    cout << prev[m] << "\n";
    return 0;
}

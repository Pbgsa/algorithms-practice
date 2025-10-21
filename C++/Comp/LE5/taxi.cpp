#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;
    vector<int> s(n);
    for (int i = 0; i < n; i++) cin >> s[i];

    int cnt1 = 0, cnt2 = 0, cnt3 = 0, cnt4 = 0;
    for (int x : s) {
        if (x == 1) cnt1++;
        else if (x == 2) cnt2++;
        else if (x == 3) cnt3++;
        else cnt4++;
    }

    int taxis = cnt4;

    int pair31 = min(cnt3, cnt1);
    taxis += cnt3; 
    cnt1 -= pair31;

    taxis += cnt2 / 2;
    if (cnt2 % 2) {
        taxis++;
        cnt1 -= min(2, cnt1);
    }

    if (cnt1 > 0)
        taxis += (cnt1 + 3) / 4;

    cout << taxis << "\n";
    return 0;
}
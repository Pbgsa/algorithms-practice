#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;


int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;

    while (t--) {
        string s;
        cin >> s;

        string even, odd;

        for (int i = 0; i < s.size(); i++) {
            if (i%2 == 0) {
                even.push_back(s[i]);
            } else {
                odd.push_back(s[i]);
            }
        }

        cout << even << ' ' << odd << '\n';
    }
       
    return 0;
}

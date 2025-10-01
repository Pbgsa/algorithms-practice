#include <bits/stdc++.h>
using namespace std;

#define pb push_back
#define all(v) v.begin(), v.end()
using ll = long long;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    string s;
    cin >> s;

    string formed_word;
    int j = 0;
    for (char c : s) {
        formed_word.push_back(c);
        j++;
        if (formed_word.size() >= 3 && formed_word.substr(j-3, 3) == "ABC") {
            formed_word.erase(j-3, 3);
            j -= 3;
        }
    }

    cout << formed_word << '\n';

    
    return 0;
}
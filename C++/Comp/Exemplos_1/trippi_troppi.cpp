// E - Trippi Troppi 
#include <iostream>
#include <algorithm>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int t, n;
    cin >> t;
    n = t;
    string words[t];
    while (t--) {
        // Read a string until break of line
        string s;
        getline(cin >> ws, s);

        // Create a abreviated version of the string with first letter of each word
        string abbr;
        bool new_word = true;
        for (char c : s) {
            if (c == ' ') {
                new_word = true;
            } else {
                if (new_word) {
                    abbr += c;
                    new_word = false;
                }
            }
        }
        words[t] = abbr;
    }

    reverse(words, words + n);
    for (int i = 0; i < n; i++) {
        cout << words[i] << "\n";
    }
    return 0;
}

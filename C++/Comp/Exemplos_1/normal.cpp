// D - Normal Problem 
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int t, n;
    cin >> t; // number of words only with letters q, p and w
    n = t; // Store original count for output loop
    // Array of strings to hold the words
    string words[t];
    while (t--) {
        cin >> words[t];
        // Invert the word
        reverse(words[t].begin(), words[t].end());
        // Change q to p and p to q and keep w as it is
        for (char &c : words[t]) {
            if (c == 'q') {
                c = 'p';
            } else if (c == 'p') {
                c = 'q';
            }
        }
    }
    // Output the transformed words
    for (int i = n-1; i >= 0; i--) {
        cout << words[i] << "\n";
    }
    
    return 0;
}

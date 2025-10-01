#include <iostream> 
#include <algorithm>
#include <vector> 
using namespace std;

// Exemplo: Normal Problem (Codeforces 2044B)
void normal_problem_example() {
    int t;
    cin >> t;
    while (t--) {
        string s;
        cin >> s;
        reverse(s.begin(), s.end());
        for (char &c : s) {
            if (c == 'q') c = 'p';
            else if (c == 'p') c = 'q';
        }
        cout << s << "\n";
    }
}

// Exemplo: Trippi Troppi (Codeforces 2094A)
// Estratégia: pegar a primeira letra de cada palavra
void trippi_troppi_example() {
    int t;
    cin >> t;
    cin.ignore(); // limpar buffer
    while (t--) {
        string s;
        getline(cin, s);

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
        cout << abbr << "\n";
    }
}

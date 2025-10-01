// C - Broken Keyboard (a.k.a. Beiju Text) 
#include <iostream>
#include <list>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    // Read a sequnce of phrases until EOF
    string phrase;
    while (getline(cin, phrase)) {
        list<char> result;
        auto it = result.begin();
        for (char c : phrase) {
            if (c == '[') {
                it = result.begin();
            } else if (c == ']') {
                it = result.end();
            } else {
                result.insert(it, c);
            }
        }

        for (char c : result) {
            cout << c;
        }
        cout << "\n";
    }

    return 0;
}
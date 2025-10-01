#include <bits/stdc++.h>

using namespace std;

void isWeird(int n) {
    if (n%2 != 0) {
        cout << "Weird" << endl;
    } else if (n >= 2 && n <= 5) {
        cout << "Not Weird" << endl;
    } else if (n >= 6 && n <= 20) {
        cout << "Weird" << endl;
    } else {
        cout << "Not Weird" << endl;
    }
}

int main() {
    int n;
    cin >> n;

    isWeird(n);

    return 0;
}
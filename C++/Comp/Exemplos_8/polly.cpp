#include <bits/stdc++.h>
using namespace std;

#define pb push_back
#define all(v) v.begin(), v.end()
using ll = long long;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    // Read a even number of lines until EOF
    // For each pair of lines, first line a list of integers coeficients
    // Second line a list of x values
    string line;
    while (getline(cin, line)) {
        // Read coefficients
        stringstream ss1(line);
        vector<int> coef;
        int num;
        while (ss1 >> num) {
            coef.pb(num);
        }

        // Read x values
        getline(cin, line);
        stringstream ss2(line);
        vector<int> x_values;
        while (ss2 >> num) {
            x_values.pb(num);
        }
        
        // print the format of the polynomial
        for (int x : x_values) {
            ll result = 0;
            ll power = 1; // x^0
            for (int c : coef) {
                result += c * power;
                power *= x;
            }
            cout << result << " ";
        }
        cout << "\n";   
    }


    return 0;
}
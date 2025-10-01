// B - Maximise The Score 
#include <iostream>
#include <algorithm>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int t, x;
    cin >> t;
    x = t;

    int score[t];
    while (t--)
    {
        int n;
        cin >> n;
        int arr[2*n];
        for (int i = 0; i < 2*n; i++) {
            cin >> arr[i];
        }
        sort(arr, arr + 2*n);

        int s = 0;
        for (int i = 0; i < 2*n; i += 2) {
            s += arr[i];
        }
        score[t] = s;
    }

    for (int i = x-1; i >= 0; i--) {
        cout << score[i] << "\n";
    }

    return 0;
}

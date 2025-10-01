// B - Ferry Loading IV 
#include <iostream>
#include <queue>
using namespace std;

void solve(queue<int>& left, queue<int>& right, int l) {
    int trips = 0;
    while (!left.empty() || !right.empty()) {
        int space = l;

        // Try to load from the left side
        while (!left.empty() && left.front() <= space) {
            space -= left.front();
            left.pop();
        }
        trips++;

        // If both sides are empty is done
        if (left.empty() && right.empty()) {
            break;
        }

        // Try to load from the right side
        space = l;
        while (!right.empty() && right.front() <= space) {
            space -= right.front();
            right.pop();
        }
        trips++;
    }

    cout << trips << "\n";
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int c;
    cin >> c;
    for (int i = 0; i < c; i++) {
        int l, m;
        cin >> l >> m;

        // Convert l to meters to centimeters
        l *= 100;

        // Read the lengths of the cars and the side the cars are on
        queue<int> left, right;

        string side;
        int car_length;
        for (int j = 0; j < m; j++) {
            cin >> car_length >> side;
            if (side == "left") {
                left.emplace(car_length);
            } else {
                right.emplace(car_length);
            }
        }

        solve(left, right, l);
    }

    return 0;
}
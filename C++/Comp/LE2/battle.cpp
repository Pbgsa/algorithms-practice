#include <bits/stdc++.h>
using namespace std;

#define pb push_back
#define all(v) v.begin(), v.end()
using ll = long long;

void war_result(priority_queue<int>& greens, priority_queue<int>& blues, int& fields) {
    while(1) {
        if (greens.empty() && blues.empty()) {
            cout << "green and blue died" << '\n';
            return;
        } else if (blues.empty()) {
            cout << "green wins" << '\n';
            while (!greens.empty())
            {
                cout << greens.top() << '\n';
                greens.pop();
            }
            return;
        } else if (greens.empty()) {
            cout << "blue wins" << '\n';
            while (!blues.empty())
            {
                cout << blues.top() << '\n';
                blues.pop();
            }
            return;
        } else {
            vector<int> remains;
            for(int i = 0; i < fields; i++) {
                int sg = greens.top();
                greens.pop();

                int sb = blues.top();
                blues.pop();

                int res = sg - sb;
                remains.pb(res);

                if (greens.empty() || blues.empty()) {
                    break;
                }
            }

            for(auto res:remains) {
                if (res > 0) {
                    greens.push(abs(res));
                } else if (res < 0) {
                    blues.push(abs(res));
                }
            }
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    for (int case_id = 0; case_id < t; case_id++) {
        int fields, sg, sb;

        cin >> fields >> sg >> sb;

        priority_queue<int> greens, blues;
        for (int i = 0; i < sg; i++) {
            int power;
            cin >> power;
            
            greens.push(power);
        }
        
        for (int i = 0; i < sb; i++) {
            int power;
            cin >> power;

            blues.push(power);
        }


        war_result(greens, blues, fields);
        if (case_id != t - 1) cout << '\n';
    }

    return 0;
}
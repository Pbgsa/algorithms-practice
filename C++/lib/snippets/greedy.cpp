#include <bits/stdc++.h>
using namespace std;

/* Escolhe a melhor opção local em cada 
passo, esperando chegar ao ótimo global.*/

// Interval Scheduling (Seleção de Intervalos)
struct Interval {
    int start, end;
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;
    vector<Interval> tasks(n);
    for (int i = 0; i < n; i++)
        cin >> tasks[i].start >> tasks[i].end;

    // Ordena por tempo de término
    sort(tasks.begin(), tasks.end(), [](auto &a, auto &b) {
        return a.end < b.end;
    });

    int count = 0, last_end = -1;
    for (auto &t : tasks) {
        if (t.start >= last_end) {
            count++;
            last_end = t.end;
        }
    }

    cout << count << "\n";
}

// Coin Change (Versão Gulosa)
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    vector<int> coins = {100, 50, 25, 10, 5, 1};
    int value;
    cin >> value;

    int count = 0;
    for (int c : coins) {
        count += value / c;
        value %= c;
    }

    cout << count << "\n";
}

// Activity/Job Selection with Profit (Variante Greedy + Sort)
struct Job {
    int start, end, profit;
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;
    vector<Job> jobs(n);
    for (int i = 0; i < n; i++)
        cin >> jobs[i].start >> jobs[i].end >> jobs[i].profit;

    sort(jobs.begin(), jobs.end(), [](auto &a, auto &b) {
        return a.end < b.end;
    });

    int total_profit = 0, last_end = 0;
    for (auto &job : jobs) {
        if (job.start >= last_end) {
            total_profit += job.profit;
            last_end = job.end;
        }
    }

    cout << total_profit << "\n";
}
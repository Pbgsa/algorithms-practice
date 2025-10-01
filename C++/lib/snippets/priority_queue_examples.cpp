#include <bits/stdc++.h>
using namespace std;

// priority_queue
// pq.push(x) → insere.
// pq.pop() → remove o topo.
// pq.top() → acessa o topo (maior ou menor, dependendo da comparação).
// pq.empty() → verifica se está vazia.

// Exemplos de uso de priority_queue
void priority_queue_examples() {
    // Max-heap (default)
    priority_queue<int> pq;
    pq.push(10);
    pq.push(5);
    pq.push(20);

    cout << pq.top() << "\n"; // 20 (maior)

    pq.pop(); // remove 20
    cout << pq.top() << "\n"; // 10

    // Min-heap
    priority_queue<int, vector<int>, greater<int>> minpq;
    minpq.push(10);
    minpq.push(5);
    minpq.push(20);

    cout << minpq.top() << "\n"; // 5 (menor)
}
#include <iostream> 
#include <queue>
#include <vector> 
using namespace std;

// q.push(x) → insere no final.
// q.pop() → remove da frente.
// q.front() → acessa primeiro elemento.
// q.back() → acessa último elemento.
// q.empty() → verifica se está vazia.
// Uso típico: simulação de filas, BFS.

// Exemplo: Ferry Loading IV (UVA 11034)
// Simula travessias do ferry com duas filas (left/right)
void ferry_loading_example(queue<int>& left, queue<int>& right, int l) {
    int trips = 0;
    while (!left.empty() || !right.empty()) {
        int space = l;
        while (!left.empty() && left.front() <= space) {
            space -= left.front();
            left.pop();
        }
        trips++;
        if (left.empty() && right.empty()) break;

        space = l;
        while (!right.empty() && right.front() <= space) {
            space -= right.front();
            right.pop();
        }
        trips++;
    }
    cout << trips << "\n";
}

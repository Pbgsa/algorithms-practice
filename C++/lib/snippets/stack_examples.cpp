#include <iostream> 
#include <stack>
#include <vector> 
using namespace std;

// s.push(x) → insere no topo.
// s.pop() → remove o topo.
// s.top() → acessa topo.
// s.empty() → retorna true se vazia.
// Uso típico: problemas LIFO (último que entra, sai primeiro).

// Exemplo: Rails (UVA 514)
// Verifica se é possível reordenar vagões usando uma pilha
void rails_example(vector<int>& out) {
    int N = out.size();
    vector<int> input(N);
    for (int i = 0; i < N; i++) input[i] = i + 1;

    int pos_out = 0, pos_in = 0;
    stack<int> s;

    while (true) {
        if (!s.empty() && out[pos_out] == s.top()) {
            s.pop(); pos_out++;
            if (pos_out == N) break;
        } else {
            if (pos_in < N) s.push(input[pos_in++]);
            else break;
        }
    }

    if (pos_out == N) cout << "Yes\n";
    else cout << "No\n";
}

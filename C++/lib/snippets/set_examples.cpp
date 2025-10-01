#include <bits/stdc++.h>
using namespace std;

//set
// s.insert(x) → adiciona (ignora duplicatas).
// s.count(x) → retorna 1 se existe, 0 caso contrário.
// s.erase(x) → remove.
// s.lower_bound(x) → iterador para o primeiro elemento ≥ x.
// s.upper_bound(x) → iterador para o primeiro elemento > x.
// s.begin() / s.end() → iteradores de início/fim.

// Exemplos de uso de set
void set_examples() {
    set<int> s;
    s.insert(5);
    s.insert(2);
    s.insert(8);
    s.insert(5); // duplicado -> ignorado

    for (int x : s) cout << x << " "; // 2 5 8
    cout << "\n";

    // Busca
    if (s.count(5)) cout << "5 está no set\n";

    // lower_bound e upper_bound
    cout << *s.lower_bound(4) << "\n"; // 5 (primeiro >= 4)
    cout << *s.upper_bound(5) << "\n"; // 8 (primeiro > 5)

    s.erase(5); // remove 5
}

//multiset
// ms.insert(x) → adiciona x (aceita repetidos).
// ms.count(x) → número de vezes que x aparece.
// ms.find(x) → iterador para um elemento igual a x (se tiver vários, pega um deles).
// ms.erase(it) → remove apenas o elemento apontado pelo iterador.
// ms.erase(x) → remove todos os elementos iguais a x.
// ms.lower_bound(x) → iterador para o primeiro elemento ≥ x.
// ms.upper_bound(x) → iterador para o primeiro elemento > x.
// Iterar: for (int x : ms) ... → já vem ordenado.

// Exemplo
void multiset_examples() {
    multiset<int> ms;

    // Inserção (aceita repetidos)
    ms.insert(5);
    ms.insert(2);
    ms.insert(5);
    ms.insert(7);

    cout << "Conteúdo do multiset:\n";
    for (int x : ms) cout << x << " "; // 2 5 5 7
    cout << "\n";

    // Contar ocorrências
    cout << "Quantidade de 5 = " << ms.count(5) << "\n"; // 2

    // Busca
    auto it = ms.find(5); // retorna iterador para um 5
    if (it != ms.end()) cout << "Encontrou um 5\n";

    // Remover apenas UM dos 5
    ms.erase(ms.find(5));

    cout << "Depois de remover um 5:\n";
    for (int x : ms) cout << x << " "; // 2 5 7
    cout << "\n";

    // lower_bound e upper_bound funcionam igual ao set
    auto it2 = ms.lower_bound(5); // primeiro >= 5
    cout << "lower_bound(5) = " << *it2 << "\n"; // 5
}
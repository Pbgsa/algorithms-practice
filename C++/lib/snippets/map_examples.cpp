// map
#include <bits/stdc++.h>
using namespace std;

// mp[key] = val → insere/atualiza par.
// mp.count(key) → retorna 1 se chave existe, 0 caso contrário.
// mp.erase(key) → remove.
// mp.begin() / mp.end() → iteradores (ordenados pela chave).
// Iterar: for (auto [k, v] : mp) cout << k << " " << v;

// Exemplos de uso de map
void map_examples() {
    map<string, int> mp;

    // Inserção
    mp["uva"] = 3;
    mp["banana"] = 5;
    mp["maçã"] = 2;

    // Iterar
    for (auto [fruta, qtd] : mp) {
        cout << fruta << " -> " << qtd << "\n";
    }

    // Buscar
    if (mp.count("banana")) cout << "Banana existe\n";

    // Acessar valor
    cout << "qtd uva = " << mp["uva"] << "\n"; // 3

    // Atualizar
    mp["uva"]++;

    // Remover
    mp.erase("banana");
}

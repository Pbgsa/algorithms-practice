#include <iostream> 
#include <list>
#include <vector> 
using namespace std;

// lst.begin() / lst.end() → iteradores.
// lst.insert(it, x) → insere x na posição it.
// lst.erase(it) → remove na posição it.
// lst.push_back(x) → insere no final.
// lst.push_front(x) → insere no começo.
// Uso típico: manipulação de texto ou quando precisamos inserir/remover no meio sem custo alto.

// Exemplo: Beiju Text (UVA 11988)
// Manipula uma lista com iteradores dependendo dos caracteres '[' e ']'
void beiju_text_example(string phrase) {
    list<char> result;
    auto it = result.begin();
    for (char c : phrase) {
        if (c == '[') it = result.begin();
        else if (c == ']') it = result.end();
        else result.insert(it, c);
    }
    for (char c : result) cout << c;
    cout << "\n";
}

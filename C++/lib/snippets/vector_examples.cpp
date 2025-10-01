#include <iostream> 
#include <algorithm>
#include <vector> 
using namespace std;

// v.begin() → iterador para o primeiro elemento.

// v.end() → iterador depois do último elemento.

// v.size() → número de elementos.

// v.push_back(x) → adiciona x no final.

// v.pop_back() → remove último elemento.

// sort(v.begin(), v.end()) → ordena.

// lower_bound(v.begin(), v.end(), x) → primeiro elemento ≥ x.

// upper_bound(v.begin(), v.end(), x) → primeiro elemento > x.

// v[i] → acesso aleatório O(1).

// Exemplo 1: Contar elementos distintos (CSES 1621 - Distinct Numbers)
// Sorting + contagem
void distinct_numbers_example() {
    int n;
    cin >> n;
    vector<int> arr(n);
    for (int i = 0; i < n; i++) cin >> arr[i];

    sort(arr.begin(), arr.end());
    int distinct = 1;
    for (int i = 1; i < n; i++) {
        if (arr[i] != arr[i-1]) distinct++;
    }
    cout << distinct << "\n";
}

// Exemplo 2: Busca binária (SPOJ BSEARCH1 - Binary Search)
// lower_bound
void binary_search_example() {
    int n, q;
    cin >> n >> q;
    vector<int> arr(n);
    for (int i = 0; i < n; i++) cin >> arr[i];

    while (q--) {
        int x;
        cin >> x;
        auto it = lower_bound(arr.begin(), arr.end(), x);
        if (it != arr.end() && *it == x) cout << (it - arr.begin()) << "\n";
        else cout << -1 << "\n";
    }
}

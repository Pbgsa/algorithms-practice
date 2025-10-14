#include <bits/stdc++.h>
using namespace std;

// Força bruta: gerar todas as possibilidades e verificar quais satisfazem a condição.
// Usa loops, recursão ou máscaras binárias.
// Geração de todos os subconjuntos
void bruteForceSubsets(vector<int>& arr) {
    int n = arr.size();
    for (int mask = 0; mask < (1 << n); mask++) {
        cout << "{ ";
        for (int i = 0; i < n; i++) {
            if (mask & (1 << i)) cout << arr[i] << " ";
        }
        cout << "}\n";
    }
}

// Divide and Conquer (D&C): Divide o problema em partes menores, resolve cada parte e combina o resultado.
// Uso clássico de D&C
void mergeSort(vector<int>& a, int l, int r) {
    if (l >= r) return;
    int mid = (l + r) / 2;
    mergeSort(a, l, mid);
    mergeSort(a, mid + 1, r);

    vector<int> temp;
    int i = l, j = mid + 1;
    while (i <= mid && j <= r)
        temp.push_back(a[i] < a[j] ? a[i++] : a[j++]);

    while (i <= mid) temp.push_back(a[i++]);
    while (j <= r) temp.push_back(a[j++]);
    for (int k = 0; k < temp.size(); k++) a[l + k] = temp[k];
}

// Outro uso de D&C
pair<int,int> getMinMax(vector<int>& v, int l, int r) {
    if (l == r) return {v[l], v[l]};
    int mid = (l + r) / 2;
    auto left = getMinMax(v, l, mid);
    auto right = getMinMax(v, mid+1, r);
    return {min(left.first, right.first), max(left.second, right.second)};
}

// Busca Binária
// Divide o espaço de busca pela metade — usada em vetores ordenados ou funções monótonas.
// Busca de elemento em vetor ordenado
int binarySearch(vector<int>& v, int x) {
    int l = 0, r = v.size() - 1;
    while (l <= r) {
        int mid = (l + r) / 2;
        if (v[mid] == x) return mid;
        else if (v[mid] < x) l = mid + 1;
        else r = mid - 1;
    }
    return -1;
}

// Busca Ternária
// Divide o intervalo em três partes para encontrar o máximo/mínimo de uma função unimodal (aumenta até certo ponto e depois diminui).
// Função exemplo: f(x) = -x^2 + 6x + 2
double f(double x) {
    return -x*x + 6*x + 2;
}

int main() {
    double l = 0, r = 10, eps = 1e-9;
    while (r - l > eps) {
        double m1 = l + (r - l) / 3;
        double m2 = r - (r - l) / 3;
        if (f(m1) < f(m2)) l = m1;  // procura máximo
        else r = m2;
    }
    cout << fixed << setprecision(6);
    cout << "x max = " << l << ", f(x) = " << f(l) << "\n";
}
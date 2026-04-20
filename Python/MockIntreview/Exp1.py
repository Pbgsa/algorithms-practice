# Seguir os passos da Mock Interview :
# 1. Entender o problema (repetir/escrever o problema, identificar os inputs e outputs, entender as restrições)
# 2. Fazer perguntas de clarificação
# 3. Pensar primeiro em uma solução ingênua (brute-force) e depois otimizar
# 4. Escrever o código
# 5. Testar o código passando caso teste lendo o codigo
# 6. Analisar a complexidade do código (tempo e espaço)

# =========================
# 1. Entender o problema
# Dado 2 strings word1 e word2. Concatene as strings adicionando uma letra
# em ordem alternada, comecando com word1. Se uma string for mais longa que a outra,
# adicione o restante dela no final da string resultante. Retorne a string resultante.

# =========================
# Exemplo 1:
# Input: word1 = "abc", word2 = "pqr"
# Output: "apbqcr"  

# =========================
# 2. Fazer perguntas de clarificação
# - As strings podem conter caracteres especiais ou apenas letras?
# Sim
# - As strings podem ser vazias?
# Sim
# - As strings podem conter letras maiúsculas e minúsculas?
# Sim

# =========================
# 3. Pensar primeiro em uma solução ingênua (brute-force) e depois otimizar
# Solução ingênua: Iterar sobre as strings usando um loop e concatenar os 
# caracteres alternadamente. Se uma string for mais longa, adicionar o restante dela no final da string resultante.
# Solução otimizada: Usar a função zip_longest do módulo itertools para iterar 
# sobre as strings e concatenar os caracteres alternadamente, preenchendo com uma string vazia quando uma string for mais curta.

# =========================
# 4. Escrever o código:
from itertools import zip_longest

class Solution:
    def mergeAlternately(self, word1: str, word2: str) -> str:
        result = []
        for c1, c2 in zip_longest(word1, word2, fillvalue=''):
            result.append(c1)
            result.append(c2)
        return ''.join(result)
    
# =========================
# 5. Testar o código passando caso teste lendo o codigo
solution = Solution()
word1 = "abc"
word2 = "pqr"
print(solution.mergeAlternately(word1, word2))  # Output: "apbqcr"
# =========================

# 6. Analisar a complexidade do código (tempo e espaço)
# A complexidade de tempo é O(n) onde n é o comprimento da string mais longa, pois estamos iterando sobre ambas as strings uma vez. 
# A complexidade de espaço é O(n) para armazenar a string resultante.


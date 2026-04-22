class Solution:
    def gcdOfStrings(self, str1: str, str2: str) -> str:
        # Verificar se a concatenação de str1 e str2 é igual à concatenação de str2 e str1
        if str1 + str2 != str2 + str1:
            return ""
        
        # Encontrar o comprimento do maior divisor comum
        def gcd(a, b):
            while b:
                a, b = b, a % b
            return a
        
        gcd_length = gcd(len(str1), len(str2))
        
        # Retornar o prefixo comum de comprimento gcd_length
        return str1[:gcd_length]
    
# A complexidade de tempo é O(n) onde n é o comprimento da string mais longa, pois estamos verificando a concatenação das strings e calculando o gcd.
# A complexidade de espaço é O(n) para armazenar a string resultante.
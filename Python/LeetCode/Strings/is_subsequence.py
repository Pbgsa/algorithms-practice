class Solution:
    def isSubsequence(self, s: str, t: str) -> bool:
        len_s = len(s)
        len_t = len(t)

        i = 0
        if len_s == 0:
            return True

        for c in t:
            if s[i] == c:
                i += 1
            if i == len_s:
                return True

        return False

# A complexidade de tempo é O(n) onde n é o comprimento da string t, pois estamos iterando sobre a string t uma vez.
# A complexidade de espaço é O(1) para armazenar as variáveis auxiliares.
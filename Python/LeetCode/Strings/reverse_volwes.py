from typing import char

class Solution:
    def reverseVowels(self, s: str) -> str:
        only_vowels = ""

        for c in s:
            if self.is_vowal(c):
                only_vowels += c

        only_vowels = only_vowels[::-1]

        chars = list(s)
        j = 0
        n = len(only_vowels)
        for i in range(len(s)):
            if j == n:
                break
            if self.is_vowal(s[i]):
                chars[i] = only_vowels[j]
                j+=1
        
        s1 = "".join(chars)

        return s1    

    def is_vowal(self, c: char) -> bool:
        return c.lower() in 'aeiou'
    
# A complexidade de tempo é O(n) onde n é o comprimento da string s, pois estamos iterando sobre a string s algumas vezes (para extrair as vogais e para reconstruir a string). A complexidade de espaço é O(n) devido à string `only_vowels` e à lista `chars` que armazenam os caracteres da string.  

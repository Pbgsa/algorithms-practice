from typing import List

class Solution:
    def compress(self, chars: List[str]) -> int:
        write = 0
        read = 0
        n = len(chars)

        while read < n:
            current_char = chars[read]
            count = 0

            while read < n and chars[read] == current_char:
                read += 1
                count += 1

            chars[write] = current_char
            write += 1

            if count > 1:
                for digit in str(count):
                    chars[write] = digit
                    write += 1

        return write
    
# A complexidade de tempo é O(n) onde n é o comprimento da lista chars, pois estamos iterando sobre a lista chars uma vez. A complexidade de espaço é O(1) para armazenar as variáveis auxiliares, além do espaço de saída que é O(n) no pior caso quando todos os caracteres são diferentes.
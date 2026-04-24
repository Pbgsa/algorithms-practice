class Solution:
    def kidsWithCandies(self, candies: List[int], extraCandies: int) -> List[bool]:
        result = []
        num_max = 0

        for qtd in candies:
            num_max = max(qtd, num_max)

        for qtd in candies:
            if (qtd+extraCandies) < num_max:
                result.append(False)
            else:
                result.append(True)
        
        return result

# A complexidade de tempo é O(n) onde n é o número de crianças, pois estamos iterando sobre a lista de candies duas vezes. A complexidade de espaço é O(n) para armazenar a lista resultante.
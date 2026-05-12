from typing import Counter, List

class Solution:
    def uniqueOccurrences(self, arr: List[int]) -> bool:
        count = Counter(arr)

        # Brute Force
        # for n in count:
        #     for m in range(n+1, len(count)+1):
        #         if count[n] == count[m]:
        #             return False
        
        # return True

        occr_array = []

        for n, occr in count.items():
            occr_array.append(occr)

        res = Counter(occr_array)

        for n in res:
            if res[n] > 1:
                return False

        return True
    
# A complexidade de tempo é O(n) onde n é o comprimento da lista arr, pois estamos iterando sobre a lista arr para contar as ocorrências. A complexidade de espaço é O(n) para armazenar o contador e a lista de ocorrências.

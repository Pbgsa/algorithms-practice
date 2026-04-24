class Solution:
    def findDifference(self, nums1: List[int], nums2: List[int]) -> List[List[int]]:
        mp1 = defaultdict(int)
        mp2 = defaultdict(int)

        n = len(nums1)
        m = len(nums2)

        i = 0
        while i < n or i < m:
            if i < n:
                mp1[nums1[i]] += i
            if i < m:
                mp2[nums2[i]] += i
            i += 1
        
        ans1 = []
        ans2 = []
        for key, value in mp1.items():
            if not key in mp2:
                ans1.append(key)

        for key, value in mp2.items():
            if not key in mp1:
                ans2.append(key)

        return [ans1, ans2]

# A complexidade de tempo é O(n + m) onde n e m são os comprimentos das listas nums1 e nums2, respectivamente, pois estamos iterando sobre ambas as listas uma vez. A complexidade de espaço é O(n + m) para armazenar os dicionários mp1 e mp2, bem como as listas ans1 e ans2.

# Versão otimizada usando sets:
class Solution:
    def findDifference(self, nums1: List[int], nums2: List[int]) -> List[List[int]]:
        set1 = set(nums1)
        set2 = set(nums2)

        # set1 - set2 retorna os elementos que estão em set1 mas não estão em set2
        ans1 = list(set1 - set2)
        # set2 - set1 retorna os elementos que estão em set2 mas não estão em set1
        ans2 = list(set2 - set1)

        return [ans1, ans2]
 
# A complexidade de tempo é O(n + m) onde n e m são os comprimentos das listas nums1 e nums2, respectivamente, pois estamos iterando sobre ambas as listas para criar os sets e depois para calcular a diferença. A complexidade de espaço é O(n + m) para armazenar os sets e as listas ans1 e ans2.
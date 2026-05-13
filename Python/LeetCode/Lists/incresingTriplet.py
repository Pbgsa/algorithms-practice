from typing import List

class Solution:
    def increasingTriplet(self, nums: List[int]) -> bool:
        n = len(nums)

        # Brute Force
        # for i in range(n):
        #     for j in range(i+1, n):
        #         if nums[i] < nums[j]:
        #             for k in range(j+1, n):
        #                 if nums[j] < nums[k]:
        #                     return True

        # return False
 
        first = second = float('inf')
        for num in nums:
            if num <= first:
                first = num
            elif num <= second:
                second = num
            else:
                return True
        
        return False
    
# A complexidade de tempo é O(n) onde n é o comprimento da lista nums, pois estamos iterando sobre a lista nums uma vez. A complexidade de espaço é O(1) para armazenar as variáveis auxiliares first e second.
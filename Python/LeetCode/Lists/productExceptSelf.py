from typing import List

class Solution:
    def productExceptSelf(self, nums: List[int]) -> List[int]:
        n = len(nums)
        output = [1] * n

        for i in range(1, n):
            output[i] = output[i-1] * nums[i-1]

        right_product = 1
        for i in range(n-1, -1, -1):
            output[i] *= right_product
            right_product *= nums[i]

        return output
    
# A complexidade de tempo é O(n) onde n é o comprimento da lista nums, pois estamos iterando sobre a lista nums duas vezes. A complexidade de espaço é O(1) para armazenar as variáveis auxiliares, além do espaço de saída que é O(n).
from typing import List

class Solution:
    def twoSum(self, nums: List[int], target: int) -> List[int]:
        index1 = 0
        index2 = 1

        for i in range(len(nums)):
            for j in range(i+1, len(nums)):
                if ((nums[i] + nums[j]) == target):
                    index1 = i
                    index2 = j

        return [index1, index2]
    
# This solution is a brute-force approach that checks all possible pairs of numbers in the list to find the two that add up to the target. The time complexity of this solution is O(n^2) due to the nested loops, and the space complexity is O(1) since we are only using a constant amount of extra space for the indices.
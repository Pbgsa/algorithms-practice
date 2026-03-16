from Python.snippets import List

class Solution:
    def moveZeroes(self, nums: List[int]) -> None:
        """
        Do not return anything, modify nums in-place instead.
        """
        i = len(nums) 
        while(i != 0):
            i -= 1
            if (nums[i] == 0):
                nums.pop(i)
                nums.append(0)

# The time complexity of this solution is O(n^2) in the worst case due to the use of the `pop` method on the list, and the space complexity is O(1) since we are modifying the list in place without using any additional data structures.

# Optimized solution using two pointers
class Solution:
    def moveZeroes(self, nums: List[int]) -> None:
        """
        Do not return anything, modify nums in-place instead.
        """
        non_zero_index = 0
        
        for i in range(len(nums)):
            if nums[i] != 0:
                nums[non_zero_index] = nums[i]
                non_zero_index += 1
        
        for i in range(non_zero_index, len(nums)):
            nums[i] = 0

# The time complexity of this solution is O(n) since we traverse the list twice, and the space complexity is O(1) since we are modifying the list in place without using any additional data structures.
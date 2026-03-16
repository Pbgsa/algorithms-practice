from Python.snippets import List

class Solution:
    def searchInsert(self, nums: List[int], target: int) -> int:
        point_init = 0
        point_end = len(nums)

        while (point_init <= point_end):
            m = ((point_end - point_init) // 2) + point_init
            if (m >= len(nums)):
                return len(nums)
            if (nums[m] == target):
                return m
            elif (nums[m] > target):
                point_end = m-1
            else:
                point_init = m+1
        
        return point_init
    
# The time complexity of this solution is O(log n) since we are halving the search space at each step, and the space complexity is O(1) since we are using only a constant amount of extra space.
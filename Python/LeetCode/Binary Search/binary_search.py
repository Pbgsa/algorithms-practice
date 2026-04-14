from Python.snippets import List

class Solution:
    def search(self, nums: List[int], target: int) -> int:
        point_init = 0
        point_end = len(nums)
        index = -1

        while (point_end >= point_init):
            m = (point_end - point_init // 2) + point_init

            if (m >= len(nums)):
                break
            if (nums[m] == target):
                index = m
                break
            elif (nums[m] > target):
                point_end = m-1
            else:
                point_init = m+1
        
        return index

# The time complexity of this solution is O(log n) since we are halving the search space at each step, and the space complexity is O(1) since we are using only a constant amount of extra space.
from Python.snippets import List


class Solution:
    def canJump(self, nums: List[int]) -> bool:
        n = len(nums)
        reach = 0

        for i in range(n):
            if (i > reach):
                return False
            reach = max(reach, i + nums[i])
        
        return True

# The time complexity of this algorithm is O(n) because we traverse the list once. The space complexity is O(1) since we only use a constant amount of extra space to store the reach variable.
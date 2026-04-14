from typing import List

class Solution:
    def twoSum(self, nums: List[int], target: int) -> List[int]:
        mp = {}
        n = len(nums)

        for i in range(n):
            mp[nums[i]] = i

        for i in range(n):
            complement = target - nums[i]
            if complement in mp and mp[complement] != i:
                return [i, mp[complement]]
        
        return []
    
# The time complexity of this solution is O(n) because we traverse the list of numbers twice: once to build the hash map and once to find the complement. The space complexity is also O(n) in the worst case if all numbers are unique and stored in the hash map.
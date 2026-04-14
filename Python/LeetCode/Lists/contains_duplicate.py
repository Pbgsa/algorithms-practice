from typing import List

class Solution:
    def containsDuplicate(self, nums: List[int]) -> bool:
        nums.sort()

        for i in range(0, len(nums)-1):
            if (nums[i] == nums[i+1]):
                return True
        
        return False
    
# This solution first sorts the input list, which takes O(n log n) time. Then it iterates through the sorted list to check for adjacent duplicates, which takes O(n) time. Therefore, the overall time complexity of this solution is O(n log n). The space complexity is O(1) if we ignore the space used by the sorting algorithm, or O(n) if we consider the space used by the sorting algorithm.

# Optimized solution using a set
class Solution:
    def containsDuplicate(self, nums: List[int]) -> bool:
        seen = set()

        for num in nums:
            if num in seen:
                return True
            seen.add(num)
        
        return False
    
# This optimized solution uses a set to keep track of the numbers we have seen as we iterate through the list. The time complexity of this solution is O(n) because we are doing a single pass through the list, and the space complexity is also O(n) in the worst case if all numbers are unique.
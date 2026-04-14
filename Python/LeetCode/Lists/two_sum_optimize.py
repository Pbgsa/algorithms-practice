from typing import List

class Solution:
    def twoSum(self, nums: List[int], target: int) -> List[int]:
        point_initial = 0
        point_end = len(nums) - 1

        sorted_nums = sorted(nums)

        target_sum = sorted_nums[point_initial] + sorted_nums[point_end]

        while target_sum != target:
            if target_sum < target:
                point_initial += 1
            else:
                point_end -= 1

            target_sum = sorted_nums[point_initial] + sorted_nums[point_end]

        index1 = nums.index(sorted_nums[point_initial])
        index2 = nums.index(sorted_nums[point_end], index1 + 1) if sorted_nums[point_initial] == sorted_nums[point_end] else nums.index(sorted_nums[point_end])

        return [index1, index2]
    
# This solution is optimized in terms of time complexity compared to the brute-force approach. The sorting step takes O(n log n) time, and the two-pointer technique takes O(n) time, resulting in an overall time complexity of O(n log n). The space complexity is O(n) due to the sorted array.
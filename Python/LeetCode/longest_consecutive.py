from typing import List

class Solution:
    def longestConsecutive(self, nums: List[int]) -> int:
        s = set(nums)
        longest = 0

        for num in s:
            if num - 1 not in s:
                curr_num = num
                streak = 1

                while curr_num + 1 in s:
                    curr_num += 1
                    streak += 1

                longest = max(streak, longest)

        return longest
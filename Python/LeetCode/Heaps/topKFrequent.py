from typing import Counter, List
import heapq

class Solution:
    def topKFrequent(self, nums: List[int], k: int) -> List[int]:
        count = Counter(nums)
        hp = []

        for num, freq in count.items():
            heapq.heappush(hp, (freq, num))
            if len(hp) > k:
                heapq.heappop(hp)

        return [num for freq, num in hp]
        
# The time complexity of this solution is O(n log k) since we traverse the list once and maintain a heap of size k, and the space complexity is O(n) since we store the frequency of each element in a dictionary.
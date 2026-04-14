from typing import List
import heapq

class Solution:
    def findKthLargest(self, nums: List[int], k: int) -> int:
        hp = []

        for num in nums:
            heapq.heappush(hp, num)
            if len(hp) > k:
                heapq.heappop(hp)
        
        return heapq.heappop(hp)
    
# The time complexity of this solution is O(n log k) since we traverse the list once and maintain a heap of size k, and the space complexity is O(k) since we store at most k elements in the heap.
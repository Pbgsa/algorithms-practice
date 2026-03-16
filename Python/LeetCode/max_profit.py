from Python.snippets import List

class Solution:
    def maxProfit(self, prices: List[int]) -> int:
        max_price = 0
        max_profit = 0
        for num in prices[::-1]:
            if (num > max_price):
                max_price = num
            if (max_profit <= max_price - num):
                max_profit = max_price - num
                
        return max_profit

# The time complexity of this solution is O(n) since we traverse the list once, and the space complexity is O(1) since we are using only a constant amount of extra space.
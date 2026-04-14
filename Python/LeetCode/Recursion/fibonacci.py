class Solution:
    def fib(self, n: int) -> int:
        if n == 0:
            return 0
        elif n == 1:
            return 1
        else:
            return self.fib(n-1) + self.fib(n-2)
        
# The time complexity of this solution is O(2^n) since we are making two recursive calls for each value of n, and the space complexity is O(n) due to the maximum depth of the recursion stack.

# A more efficient solution would be to use dynamic programming or memoization to avoid redundant calculations, which would reduce the time complexity to O(n) and space complexity to O(n) or O(1) depending on the implementation.
from typing import List

class Solution:
    def generate(self, ans: list[str], s: str, open: int, close: int, n: int) -> None:
        if n == open and close == n:
            ans.append(s)
            return
        if open > close:
            self.generate(ans, s + ")", open, close+1, n)
        if open < n:
            self.generate(ans, s + "(", open+1, close, n)
            
    def generateParenthesis(self, n: int) -> List[str]:
        ans: List[str] = []
        self.generate(ans, "", 0, 0, n)
        return ans

# The time complexity of this solution is O(4^n / sqrt(n)) since we are generating all possible combinations of parentheses, and the space complexity is O(4^n / sqrt(n)) due to the number of valid combinations that can be generated.
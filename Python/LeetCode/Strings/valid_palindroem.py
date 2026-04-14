class Solution:
    def isPalindrome(self, s: str) -> bool:
        s = s.lower()
        result = []
        for c in s:
            if c.isalnum():
                result.append(c)

        s2 = "".join(result)

        if (s2 == s2[::-1] or len(s2) == 0):
            return True
        else:
            return False
        
# The time complexity of this solution is O(n) due to the single pass through the string and the reverse operation, and the space complexity is O(n) due to the additional list used to store the cleaned characters.
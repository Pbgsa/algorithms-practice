class Solution:
    def isValid(self, s: str) -> bool:
        stack = []

        for c in s:
            if c == '(' or c == '[' or c == '{':
                stack.append(c)
            else:
                if len(stack) == 0:
                    return False
                if c == ')' and stack[-1] == '(':
                    stack.pop()
                elif c == ']' and stack[-1] == '[':
                    stack.pop()
                elif c == '}' and stack[-1] == '{':
                    stack.pop()
                else:
                    return False
        
        if len(stack) == 0:
            return True
        else:
            return False
        
# The time complexity of this solution is O(n) since we traverse the string once, and the space complexity is O(n) in the worst case if all characters are opening brackets and added to the stack.
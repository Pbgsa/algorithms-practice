class MinStack:

    def __init__(self):
        self.s = []
        self.st = []

    def push(self, val: int) -> None:
        self.s.append(val)
        if not self.st or val <= self.st[-1]:
            self.st.append(val)        

    def pop(self) -> None:
        if self.s.pop() == self.st[-1]:
            self.st.pop()

    def top(self) -> int:
        return self.s[-1]
        
    def getMin(self) -> int:
        return self.st[-1]
    
# The time complexity of each operation (push, pop, top, getMin) is O(1) since we are using two stacks to keep track of the minimum values. The space complexity is O(n) in the worst case if all elements are unique and added to both stacks.
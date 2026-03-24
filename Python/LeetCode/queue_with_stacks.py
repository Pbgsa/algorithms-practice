class MyQueue:

    def __init__(self):
        self.s = []
        self.st = []        

    def push(self, x: int) -> None:
        if not self.st:
            self.s.append(x)
        else:
            for i in range(len(self.st)):
                self.s.append(self.st.pop())
            self.s.append(x)

    def pop(self) -> int:
        if not self.s:
            return self.st.pop()
        else:
            for i in range(len(self.s)):
                self.st.append(self.s.pop())
            return self.st.pop()

    def peek(self) -> int:
        if not self.s:
            return self.st[-1]
        else:
            for i in range(len(self.s)):
                self.st.append(self.s.pop())
            return self.st[-1]

    def empty(self) -> bool:
        return (len(self.s) == 0 and len(self.st) == 0)


# The time complexity of each operation (push, pop, peek) is O(n) in the worst case since we may need to move all elements between the two stacks, and the space complexity is O(n) in the worst case if all elements are unique and added to both stacks.


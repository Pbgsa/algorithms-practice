"""
Stack and Queue Snippets
Common patterns used in coding interviews
"""

from collections import deque


# =========================
# STACK (LIFO)
# =========================

# Using list (most common in interviews)

stack = []

# Push
stack.append(10)
stack.append(20)

# Pop
top = stack.pop()   # 20

# Peek
top = stack[-1]

# Check empty
if not stack:
    print("Empty stack")


# =========================
# STACK - Example Pattern
# =========================
# Valid Parentheses

def is_valid_parentheses(s: str) -> bool:
    stack = []
    mapping = {')': '(', '}': '{', ']': '['}

    for char in s:
        if char in mapping:
            if not stack or stack.pop() != mapping[char]:
                return False
        else:
            stack.append(char)

    return not stack


# =========================
# QUEUE (FIFO)
# =========================

# Using deque (recommended)

queue = deque()

# Enqueue
queue.append(10)
queue.append(20)

# Dequeue
front = queue.popleft()   # 10

# Peek
front = queue[0]

# Check empty
if not queue:
    print("Empty queue")


# =========================
# QUEUE - Example Pattern
# =========================
# BFS (Breadth First Search)

def bfs(graph, start):
    visited = set()
    queue = deque([start])

    while queue:
        node = queue.popleft()

        if node not in visited:
            print(node)
            visited.add(node)

            for neighbor in graph[node]:
                queue.append(neighbor)


# =========================
# DEQUE (Double-ended Queue)
# =========================

dq = deque()

# Add both sides
dq.append(1)
dq.appendleft(2)

# Remove both sides
dq.pop()
dq.popleft()


# =========================
# MONOTONIC STACK (IMPORTANT)
# =========================

def next_greater_elements(nums):
    stack = []
    result = [-1] * len(nums)

    for i in range(len(nums)):
        while stack and nums[stack[-1]] < nums[i]:
            idx = stack.pop()
            result[idx] = nums[i]
        stack.append(i)

    return result


# =========================
# SLIDING WINDOW (QUEUE PATTERN)
# =========================

def sliding_window_max(nums, k):
    dq = deque()
    result = []

    for i in range(len(nums)):
        # Remove elements out of window
        if dq and dq[0] < i - k + 1:
            dq.popleft()

        # Remove smaller elements
        while dq and nums[dq[-1]] < nums[i]:
            dq.pop()

        dq.append(i)

        # Add result
        if i >= k - 1:
            result.append(nums[dq[0]])

    return result
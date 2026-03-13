"""
Python List Snippets
Common operations used in algorithm problems
"""

# =========================
# Creating Lists
# =========================

# Empty list
arr = []

# Initialize with values
arr = [1, 2, 3, 4]

# List with repeated values
arr = [0] * 5   # [0,0,0,0,0]


# =========================
# Accessing Elements
# =========================

arr = [10, 20, 30, 40]

first = arr[0]
last = arr[-1]

# Safe iteration
for x in arr:
    print(x)

# Index iteration
for i in range(len(arr)):
    print(arr[i])


# =========================
# Adding Elements
# =========================

arr = [1,2,3]

# Append at end
arr.append(4)

# Insert at position
arr.insert(1, 10)

# Extend list
arr.extend([5,6,7])


# =========================
# Removing Elements
# =========================

arr = [1,2,3,4]

# Remove last
arr.pop()

# Remove by index
arr.pop(1)

# Remove by value
arr.remove(3)


# =========================
# Searching
# =========================

arr = [5,3,8,1]

# Check existence
if 3 in arr:
    print("Found")

# Index of element
idx = arr.index(8)


# =========================
# Sorting
# =========================

arr = [5,1,3,2]

# In-place sort
arr.sort()

# Reverse sort
arr.sort(reverse=True)

# Sorted copy
new_arr = sorted(arr)


# =========================
# Slicing
# =========================

arr = [1,2,3,4,5]

# Subarray
sub = arr[1:4]

# Copy list
copy = arr[:]

# Reverse
rev = arr[::-1]


# =========================
# List Comprehension
# =========================

arr = [1,2,3,4]

squares = [x*x for x in arr]

evens = [x for x in arr if x % 2 == 0]


# =========================
# Useful Built-ins
# =========================

arr = [4,2,9,1]

min_val = min(arr)
max_val = max(arr)
total = sum(arr)
length = len(arr)


# =========================
# 2D Lists (Matrix)
# =========================

rows, cols = 3, 4

matrix = [[0]*cols for _ in range(rows)]

matrix[1][2] = 5
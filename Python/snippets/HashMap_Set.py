"""
HashMap (dict) and Set Snippets
Most used patterns in coding interviews
"""

from collections import defaultdict, Counter


# =========================
# HASH MAP (DICT)
# =========================

# Create
mp = {}

# Insert / Update
mp["a"] = 1
mp["b"] = 2

# Access
val = mp["a"]              # KeyError if not exists
val = mp.get("c", 0)      # safe access

# Check existence
if "a" in mp:
    print("Found")

# Delete
del mp["a"]

# Iterate
for key in mp:
    print(key, mp[key])

for key, value in mp.items():
    print(key, value)


# =========================
# DEFAULTDICT (VERY USEFUL)
# =========================

# Avoid checking key existence

mp = defaultdict(int)

mp["a"] += 1   # automatically initializes as 0

mp.update({"b": 2, "c": 3})   # bulk update

mp.values()   # dict_values([1, 2, 3])


# =========================
# COUNTER (FREQUENCY MAP)
# =========================

arr = [1,2,2,3,3,3]

count = Counter(arr)

print(count[2])   # 2


# =========================
# SET
# =========================

# Create
s = set()

# Add
s.add(1)
s.add(2)

# Remove
s.remove(1)      # error if not exists
s.discard(3)     # safe remove

# Check existence
if 2 in s:
    print("Found")

# Iterate
for x in s:
    print(x)


# =========================
# SET OPERATIONS
# =========================

a = {1,2,3}
b = {3,4,5}

union = a | b
intersection = a & b
difference = a - b


# =========================
# PATTERN 1: TWO SUM
# =========================

def two_sum(nums, target):
    mp = {}

    for i, num in enumerate(nums):
        diff = target - num

        if diff in mp:
            return [mp[diff], i]

        mp[num] = i

    return []


# =========================
# PATTERN 2: FREQUENCY COUNT
# =========================

def frequency_count(s):
    mp = {}

    for c in s:
        mp[c] = mp.get(c, 0) + 1

    return mp


# =========================
# PATTERN 3: VALID ANAGRAM
# =========================

def is_anagram(s, t):
    return Counter(s) == Counter(t)


# =========================
# PATTERN 4: REMOVE DUPLICATES
# =========================

def remove_duplicates(nums):
    seen = set()
    result = []

    for num in nums:
        if num not in seen:
            seen.add(num)
            result.append(num)

    return result


# =========================
# PATTERN 5: LONGEST CONSECUTIVE SEQUENCE
# =========================

def longest_consecutive(nums):
    num_set = set(nums)
    longest = 0

    for num in num_set:
        if num - 1 not in num_set:  # start of sequence
            current = num
            streak = 1

            while current + 1 in num_set:
                current += 1
                streak += 1

            longest = max(longest, streak)

    return longest


# =========================
# PATTERN 6: GROUP ANAGRAMS
# =========================

def group_anagrams(strs):
    mp = defaultdict(list)

    for word in strs:
        key = tuple(sorted(word))
        mp[key].append(word)

    return list(mp.values())
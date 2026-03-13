"""
Python String Manipulation Snippets
Common operations used in coding interviews
"""

# =========================
# Creating Strings
# =========================

s = "hello"
empty = ""

# Multi-line string
text = """This is
a multi-line
string"""


# =========================
# Accessing Characters
# =========================

s = "hello"

first = s[0]      # 'h'
last = s[-1]      # 'o'

# Iterate characters
for c in s:
    print(c)

# Iterate with index
for i in range(len(s)):
    print(i, s[i])


# =========================
# String Length
# =========================

s = "hello"
length = len(s)


# =========================
# String Slicing
# =========================

s = "hello"

# substring
sub = s[1:4]      # "ell"

# first 3 chars
first = s[:3]

# last 3 chars
last = s[-3:]

# reverse string
rev = s[::-1]


# =========================
# String Concatenation
# =========================

s1 = "hello"
s2 = "world"

result = s1 + " " + s2


# =========================
# String Comparison
# =========================

a = "abc"
b = "abc"

if a == b:
    print("equal")


# =========================
# Searching
# =========================

s = "hello world"

# check substring
if "world" in s:
    print("found")

# find index
idx = s.find("world")   # returns -1 if not found

# count occurrences
count = s.count("l")


# =========================
# Replace
# =========================

s = "hello world"

new = s.replace("world", "python")


# =========================
# Split and Join
# =========================

sentence = "I love coding"

# split into words
words = sentence.split(" ")

# join back
new_sentence = " ".join(words)


# =========================
# Changing Case
# =========================

s = "Hello World"

lower = s.lower()
upper = s.upper()
title = s.title()


# =========================
# Remove Spaces
# =========================

s = "  hello  "

# remove both sides
s1 = s.strip()

# left side
s2 = s.lstrip()

# right side
s3 = s.rstrip()


# =========================
# Check Character Types
# =========================

c = "a"

c.isalpha()
c.isdigit()
c.isalnum()
c.isspace()

# =========================
# String Sorting
# =========================

s = "hello"
sorted_s = "".join(sorted(s))


# =========================
# Convert String <-> List
# =========================

s = "hello"

chars = list(s)

# back to string
s2 = "".join(chars)


# =========================
# String Builder Pattern
# =========================

# Avoid concatenating in loop

result = []
for c in "hello":
    result.append(c)

final = "".join(result)


# =========================
# Palindrome Check
# =========================

s = "racecar"

is_pal = s == s[::-1]


# =========================
# Two Pointers (Common Pattern)
# =========================

s = "abba"

left = 0
right = len(s) - 1

while left < right:
    if s[left] != s[right]:
        print("Not palindrome")
        break
    left += 1
    right -= 1
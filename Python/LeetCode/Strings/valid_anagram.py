class Solution:
    def isAnagram(self, s: str, t: str) -> bool:
        t_list = list(t)

        for c in s:
            if (c in t_list):
                indx = t_list.index(c)
                t_list.pop(indx)
            else:
                return False
        
        if (len(t_list) == 0):
            return True
        else:
            return False

        
# The time complexity of this solution is O(n^2) in the worst case due to the use of the `in` operator and `index` method on the list, and the space complexity is O(n) due to the list created from the second string.

# Optimized solution using sorting
class Solution:
    def isAnagram(self, s: str, t: str) -> bool:
        return sorted(s) == sorted(t)
    

# The time complexity of this solution is O(n log n) due to the sorting step, and the space complexity is O(n) due to the space used by the sorted lists.
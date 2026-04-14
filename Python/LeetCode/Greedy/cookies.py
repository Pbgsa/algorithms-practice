from Python.snippets import List

class Solution:
    def findContentChildren(self, g: List[int], s: List[int]) -> int:
        g = sorted(g)
        s = sorted(s)

        childs = 0

        for cookie in s:
            if cookie >= g[childs]:
                childs += 1
            if childs >= len(g):
                break
        
        return childs

# The time complexity of this algorithm is O(n log n) due to the sorting step, where n is the length of the longer list between g and s. The space complexity is O(1) if we ignore the space used for sorting, otherwise it would be O(n) due to the space used by the sorting algorithm.
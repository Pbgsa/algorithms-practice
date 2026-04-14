# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right

from typing import Optional
from Python.snippets.Tree_Graph import TreeNode

class Solution:
    def isSameTree(self, p: Optional[TreeNode], q: Optional[TreeNode]) -> bool:
        if p and q:
            if p.val != q.val:
                return False
            else:
                return self.isSameTree(p.left, q.left) and self.isSameTree(p.right, q.right)
        elif not p and not q:
            return True
        else:
            return False

# The time complexity of this solution is O(n) since we visit each node once, where n is the number of nodes in the tree. The space complexity is O(h) where h is the height of the tree due to the recursion stack. In the worst case (a skewed tree), the space complexity can be O(n).
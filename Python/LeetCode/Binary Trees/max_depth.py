# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
#         self.max_depth = 1

from pyparsing import Optional
from Python.snippets.Tree_Graph import TreeNode

class Solution:
    def maxDepth(self, root: Optional[TreeNode]) -> int:
        if not root:
            return 0
        return 1 + max(self.maxDepth(root.right), self.maxDepth(root.left))

# The time complexity of this solution is O(n) since we visit each node once, and the space complexity is O(h) where h is the height of the tree due to the recursion stack. In the worst case (a skewed tree), the space complexity can be O(n).
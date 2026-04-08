# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right

from typing import Optional

from Python.snippets import List
from Python.snippets.Tree_Graph import TreeNode

class Solution:
    def inoderAux(self, root: Optional[TreeNode], res: List[int]) -> None:
        if root is None:
            return

        self.inoderAux(root.left, res)
        res.append(root.val)
        self.inoderAux(root.right, res)

    def inorderTraversal(self, root: Optional[TreeNode]) -> List[int]:
        res = []
        self.inoderAux(root, res)
        return res
    
# The time complexity of this solution is O(n) since we visit each node once, where n is the number of nodes in the tree. The space complexity is O(h) where h is the height of the tree due to the recursion stack. In the worst case (a skewed tree), the space complexity can be O(n).
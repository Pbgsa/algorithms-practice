# Binary Tree Level Order Traversal
# Definition for a binary tree node.
# class TreeNode:
#	def __init__(self, val=0, left=None, right=None):
#		self.val = val
#		self.left = left
# 		self.right = right

import queue
from typing import Optional

from Python.snippets import List
from Python.snippets.Tree_Graph import TreeNode


class Solution:
	def levelOrder(self, root: Optional[TreeNode]) -> List[List[int]]:
		if not root:
			result = []

		result = []
		queue = [root]

		while queue:
			level_size = len(queue)
			current_level = []

			for _ in range(level_size):
				node = queue.pop(0)
				print(node)
				current_level.append(node.val)

				if node.left:
					queue.append(node.left)
				if node.right:
					queue.append(node.right)

			result.append(current_level)

		return result
	
# The time complexity of this solution is O(n) since we visit each node once, where n is the number of nodes in the tree. The space complexity is O(w) where w is the maximum width of the tree, which occurs when the last level of the tree is fully filled. In the worst case (a complete binary tree), the space complexity can be O(n/2) = O(n).
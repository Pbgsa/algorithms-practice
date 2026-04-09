"""
# Definition for a Node.
class Node:
    def __init__(self, val = 0, neighbors = None):
        self.val = val
        self.neighbors = neighbors if neighbors is not None else []
"""

from typing import Optional
from xml.dom.minidom import Node

class Solution:
    def cloneGraph(self, node: Optional['Node']) -> Optional['Node']:
        mp = {}

        if not node:
            return node

        if len(node.neighbors) == 0:
            cp_node = Node(node.val)
            return cp_node
        
        return self.dfs(node, mp)

    def dfs(self, node: Optional['Node'], mp: dict) -> Optional['Node']:
        neighbor = []
        cp_node = Node(node.val)
        mp[node] = cp_node
        
        for i in node.neighbors:
            if i in mp:
                neighbor.append(mp[i])
            else:
                neighbor.append(self.dfs(i, mp))
        
        cp_node.neighbors = neighbor
        return cp_node
    
# The time complexity is O(N) where N is the number of nodes in the graph, since we visit each node once.
# The space complexity is O(N) due to the hash map storing the cloned nodes and the recursion stack in the worst case of a completely connected graph.
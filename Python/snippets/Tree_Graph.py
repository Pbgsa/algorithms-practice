"""
Tree and Graph Snippets
Common patterns used in coding interviews
"""

from collections import deque, defaultdict

# =========================================================
# BINARY TREE NODE
# =========================================================

class TreeNode:
    def __init__(self, val=0, left=None, right=None):
        self.val = val
        self.left = left
        self.right = right


# =========================================================
# BINARY TREE DFS TRAVERSALS
# =========================================================

def preorder(root):
    """Root -> Left -> Right"""
    if not root:
        return []
    return [root.val] + preorder(root.left) + preorder(root.right)


def inorder(root):
    """Left -> Root -> Right"""
    if not root:
        return []
    return inorder(root.left) + [root.val] + inorder(root.right)


def postorder(root):
    """Left -> Right -> Root"""
    if not root:
        return []
    return postorder(root.left) + postorder(root.right) + [root.val]


# =========================================================
# ITERATIVE TREE TRAVERSALS
# =========================================================

def preorder_iterative(root):
    if not root:
        return []

    stack = [root]
    result = []

    while stack:
        node = stack.pop()
        result.append(node.val)

        if node.right:
            stack.append(node.right)
        if node.left:
            stack.append(node.left)

    return result


def inorder_iterative(root):
    stack = []
    result = []
    curr = root

    while curr or stack:
        while curr:
            stack.append(curr)
            curr = curr.left

        curr = stack.pop()
        result.append(curr.val)
        curr = curr.right

    return result


# =========================================================
# BINARY TREE BFS / LEVEL ORDER
# =========================================================

def level_order(root):
    if not root:
        return []

    result = []
    queue = deque([root])

    while queue:
        level_size = len(queue)
        level = []

        for _ in range(level_size):
            node = queue.popleft()
            level.append(node.val)

            if node.left:
                queue.append(node.left)
            if node.right:
                queue.append(node.right)

        result.append(level)

    return result


# =========================================================
# TREE UTILITIES
# =========================================================

def max_depth(root):
    if not root:
        return 0
    return 1 + max(max_depth(root.left), max_depth(root.right))


def is_same_tree(p, q):
    if not p and not q:
        return True
    if not p or not q or p.val != q.val:
        return False
    return is_same_tree(p.left, q.left) and is_same_tree(p.right, q.right)


def invert_tree(root):
    if not root:
        return None

    root.left, root.right = root.right, root.left
    invert_tree(root.left)
    invert_tree(root.right)
    return root


# =========================================================
# LOWEST COMMON ANCESTOR (BST)
# =========================================================

def lowest_common_ancestor_bst(root, p, q):
    while root:
        if p.val < root.val and q.val < root.val:
            root = root.left
        elif p.val > root.val and q.val > root.val:
            root = root.right
        else:
            return root


# =========================================================
# GRAPH REPRESENTATION
# =========================================================

# Adjacency list example:
# graph = {
#     0: [1, 2],
#     1: [2],
#     2: [0, 3],
#     3: [3]
# }


# =========================================================
# GRAPH DFS (RECURSIVE)
# =========================================================

def dfs_recursive(graph, node, visited=None):
    if visited is None:
        visited = set()

    visited.add(node)
    print(node)

    for neighbor in graph[node]:
        if neighbor not in visited:
            dfs_recursive(graph, neighbor, visited)

    return visited


# =========================================================
# GRAPH DFS (ITERATIVE)
# =========================================================

def dfs_iterative(graph, start):
    stack = [start]
    visited = set()

    while stack:
        node = stack.pop()

        if node not in visited:
            print(node)
            visited.add(node)

            for neighbor in reversed(graph[node]):
                if neighbor not in visited:
                    stack.append(neighbor)

    return visited


# =========================================================
# GRAPH BFS
# =========================================================

def bfs(graph, start):
    queue = deque([start])
    visited = set([start])

    while queue:
        node = queue.popleft()
        print(node)

        for neighbor in graph[node]:
            if neighbor not in visited:
                visited.add(neighbor)
                queue.append(neighbor)

    return visited


# =========================================================
# NUMBER OF ISLANDS (GRID DFS)
# =========================================================

def num_islands(grid):
    if not grid:
        return 0

    rows, cols = len(grid), len(grid[0])
    count = 0

    def dfs(r, c):
        if r < 0 or c < 0 or r >= rows or c >= cols or grid[r][c] == "0":
            return

        grid[r][c] = "0"

        dfs(r + 1, c)
        dfs(r - 1, c)
        dfs(r, c + 1)
        dfs(r, c - 1)

    for r in range(rows):
        for c in range(cols):
            if grid[r][c] == "1":
                count += 1
                dfs(r, c)

    return count


# =========================================================
# CYCLE DETECTION IN UNDIRECTED GRAPH
# =========================================================

def has_cycle_undirected(graph):
    visited = set()

    def dfs(node, parent):
        visited.add(node)

        for neighbor in graph[node]:
            if neighbor not in visited:
                if dfs(neighbor, node):
                    return True
            elif neighbor != parent:
                return True

        return False

    for node in graph:
        if node not in visited:
            if dfs(node, None):
                return True

    return False


# =========================================================
# TOPOLOGICAL SORT (KAHN'S ALGORITHM)
# =========================================================

def topological_sort(graph):
    indegree = defaultdict(int)

    for node in graph:
        indegree[node]  # ensure node exists
        for neighbor in graph[node]:
            indegree[neighbor] += 1

    queue = deque([node for node in indegree if indegree[node] == 0])
    order = []

    while queue:
        node = queue.popleft()
        order.append(node)

        for neighbor in graph[node]:
            indegree[neighbor] -= 1
            if indegree[neighbor] == 0:
                queue.append(neighbor)

    if len(order) != len(indegree):
        return []  # cycle detected

    return order
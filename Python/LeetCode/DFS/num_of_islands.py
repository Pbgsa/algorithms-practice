from Python.snippets import List

class Solution:
    def numIslands(self, grid: List[List[str]]) -> int:
        row = len(grid)
        col = len(grid[0])
        n_islands = 0

        for i in range(row):
            for j in range(col):
                if grid[i][j] == '1':
                    self.dfs(grid, i, j)
                    n_islands += 1
        
        return n_islands

    def dfs(self, grid: List[List[str]], i: int, j: int) -> None:
        row = len(grid)
        col = len(grid[0])

        if i < 0 or j < 0 or i >= row or j >= col or grid[i][j] == '0':
            return
        
        grid[i][j] = '0'
        self.dfs(grid, i+1, j)
        self.dfs(grid, i, j+1)
        self.dfs(grid, i-1, j)
        self.dfs(grid, i, j-1)

# The time complexity is O(M*N) where M and N are the number of rows and columns in the grid, since we visit each cell once.
# The space complexity is O(M*N) in the worst case when the grid is filled with land, due to the recursion stack in the depth-first search.
from Python.snippets.List import List

class Solution:
    def rotate(self, matrix: List[List[int]]) -> None:
        """
        Do not return anything, modify matrix in-place instead.
        """
        n = len(matrix)

        for i in range(n):
            for j in range(i, n):
                matrix[i][j], matrix[j][i] = matrix[j][i], matrix[i][j]
        
        for i in range(n):
            matrix[i].reverse()

        print('Rotated Matrix:', matrix)

# The time complexity of this solution is O(n^2) since we traverse the matrix twice, and the space complexity is O(1) since we are modifying the matrix in place without using any additional data structures.
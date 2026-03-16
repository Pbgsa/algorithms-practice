from typing import List

class Solution:
    def spiralOrder(self, matrix: List[List[int]]) -> List[int]:
        m = len(matrix) - 1
        n = len(matrix[0]) - 1

        covered_lin = 0
        covered_col = 0

        i = 0
        j = 0

        order = []
        direction = 'right'

        while(m >= covered_lin and n >= covered_col):
            if (direction == 'right'):
                order.append(matrix[i][j])
                if (j < n):
                    j += 1
                else:
                    covered_lin += 1
                    direction = 'down'
                    i += 1
            elif (direction == 'down'):

                order.append(matrix[i][j])
                if (i < m):
                    i += 1
                else:
                    n -= 1
                    direction = 'left'
                    j -= 1
            elif (direction == 'left'):

                order.append(matrix[i][j])
                if (j > covered_col):
                    j -= 1
                else:
                    m -= 1
                    direction = 'up'
                    i -= 1
            elif (direction == 'up'):

                order.append(matrix[i][j])
                if (i > covered_lin):
                    i -= 1
                else:
                    covered_col += 1
                    direction = 'right'
                    j += 1
        
        return order

            

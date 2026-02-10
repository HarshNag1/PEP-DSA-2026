class Solution:
    def boundaryTraversal(self, matrix, n, m):
        if n == 1:
            return matrix[0]
        if m == 1:
            return [matrix[i][0] for i in range(n)]
            
        result = []
        
        # Top row
        for j in range(m):
            result.append(matrix[0][j])
            
        # Right column
        for i in range(1, n):
            result.append(matrix[i][m-1])
            
        # Bottom row
        for j in range(m-2, -1, -1):
            result.append(matrix[n-1][j])
            
        # Left column
        for i in range(n-2, 0, -1):
            result.append(matrix[i][0])
            
        return result

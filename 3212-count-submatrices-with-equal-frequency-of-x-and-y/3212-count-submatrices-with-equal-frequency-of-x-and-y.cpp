class Solution {
public:
    int numberOfSubmatrices(vector<vector<char>>& grid) {
        int rows = grid.size();
        int cols = grid[0].size();
        
        // prefX[i][j] stores the number of 'X's in the submatrix (0,0) to (i-1, j-1)
        // prefY[i][j] stores the number of 'Y's in the submatrix (0,0) to (i-1, j-1)
        vector<vector<int>> prefX(rows + 1, vector<int>(cols + 1, 0));
        vector<vector<int>> prefY(rows + 1, vector<int>(cols + 1, 0));
        
        int validSubmatrices = 0;
        
        for (int r = 0; r < rows; ++r) {
            for (int c = 0; c < cols; ++c) {
                int isX = (grid[r][c] == 'X' ? 1 : 0);
                int isY = (grid[r][c] == 'Y' ? 1 : 0);
                
                // 2D Prefix Sum Formula: 
                // Total = current + top + left - top_left_diagonal
                prefX[r+1][c+1] = isX + prefX[r][c+1] + prefX[r+1][c] - prefX[r][c];
                prefY[r+1][c+1] = isY + prefY[r][c+1] + prefY[r+1][c] - prefY[r][c];
                
                // Check if submatrix starting at (0,0) and ending at (r,c) is valid
                if (prefX[r+1][c+1] > 0 && prefX[r+1][c+1] == prefY[r+1][c+1]) {
                    validSubmatrices++;
                }
            }
        }
        
        return validSubmatrices;
    }
};
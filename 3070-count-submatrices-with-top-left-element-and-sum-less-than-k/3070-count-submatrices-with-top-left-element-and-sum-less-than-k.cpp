class Solution {
public:
    int countSubmatrices(vector<vector<int>>& grid, int k) {
        int m = grid.size();
        int n = grid[0].size();
        int count = 0;

        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                // Apply 2D Prefix Sum formula
                if (i > 0) grid[i][j] += grid[i - 1][j];
                if (j > 0) grid[i][j] += grid[i][j - 1];
                if (i > 0 && j > 0) grid[i][j] -= grid[i - 1][j - 1];

                // Since all elements are non-negative, if grid[i][j] > k,
                // all submatrices ending further right in this row will also be > k.
                if (grid[i][j] <= k) {
                    count++;
                } else {
                    // Optimization: stop processing this row further
                    break; 
                }
            }
        }

        return count;
    }
};
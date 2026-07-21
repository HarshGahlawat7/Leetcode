class Solution {
public:
    vector<vector<int>> shiftGrid(vector<vector<int>>& grid, int k) {
        int m = grid.size();
        int n = grid[0].size();
        int total = m * n;
        
        // Normalize k to avoid unnecessary full rotations
        k = k % total;
        if (k == 0) return grid;

        vector<vector<int>> result(m, vector<int>(n));

        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                // Flatten 2D index -> 1D index
                int old_1d = i * n + j;
                
                // Calculate shifted 1D index
                int new_1d = (old_1d + k) % total;
                
                // Map back to 2D coordinates in result grid
                result[new_1d / n][new_1d % n] = grid[i][j];
            }
        }

        return result;
    }
};
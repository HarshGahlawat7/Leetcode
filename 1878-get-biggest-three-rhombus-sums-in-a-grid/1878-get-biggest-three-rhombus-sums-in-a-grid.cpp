class Solution {
public:
    vector<int> getBiggestThree(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        set<int> distinctSums;

        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                // Case 1: The "Area 0" rhombus (the cell itself)
                distinctSums.insert(grid[i][j]);

                // Case 2: Rhombuses with radius k > 0
                for (int k = 1; ; ++k) {
                    // Check if the rhombus boundaries are within the grid
                    if (i - k < 0 || i + k >= m || j - k < 0 || j + k >= n) break;

                    int currentSum = 0;
                    // Top vertex: (i-k, j), Bottom: (i+k, j), Left: (i, j-k), Right: (i, j+k)
                    
                    // We traverse the 4 edges of the rhombus
                    for (int x = 0; x < k; ++x) {
                        currentSum += grid[i - k + x][j + x]; // Top to Right
                        currentSum += grid[i + x][j + k - x]; // Right to Bottom
                        currentSum += grid[i + k - x][j - x]; // Bottom to Left
                        currentSum += grid[i - x][j - k + x]; // Left to Top
                    }
                    
                    distinctSums.insert(currentSum);
                }
                
                // Optional optimization: Keep only the top 3 largest elements in the set
                while (distinctSums.size() > 300) { // Keep a buffer, then prune at the end
                     distinctSums.erase(distinctSums.begin());
                }
            }
        }

        // Convert set to vector and return top 3 in descending order
        vector<int> result(distinctSums.rbegin(), distinctSums.rend());
        if (result.size() > 3) {
            result.resize(3);
        }
        return result;
        
    }
};
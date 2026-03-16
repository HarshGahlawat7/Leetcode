class Solution {
public:
    vector<int> getBiggestThree(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        set<int> distinctSums;

        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                
                distinctSums.insert(grid[i][j]);

                for (int k = 1; ; ++k) {
                    if (i - k < 0 || i + k >= m || j - k < 0 || j + k >= n) break;

                    int currentSum = 0;
                   
                    for (int x = 0; x < k; ++x) {
                        currentSum += grid[i - k + x][j + x]; // Top to Right
                        currentSum += grid[i + x][j + k - x]; // Right to Bottom
                        currentSum += grid[i + k - x][j - x]; // Bottom to Left
                        currentSum += grid[i - x][j - k + x]; // Left to Top
                    }
                    
                    distinctSums.insert(currentSum);
                }
                
                while (distinctSums.size() > 300) { 
                     distinctSums.erase(distinctSums.begin());
                }
            }
        }

        vector<int> result(distinctSums.rbegin(), distinctSums.rend());
        if (result.size() > 3) {
            result.resize(3);
        }
        return result;
        
    }
};
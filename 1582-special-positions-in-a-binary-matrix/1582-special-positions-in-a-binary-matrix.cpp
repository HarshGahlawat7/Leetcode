class Solution {
public:
    int numSpecial(vector<vector<int>>& mat) {
        int m = mat.size();
        int n = mat[0].size();
        
        // Vectors to store the count of 1s in each row and column
        vector<int> rowCount(m, 0);
        vector<int> colCount(n, 0);
        
        // First pass: Fill the count vectors
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                if (mat[i][j] == 1) {
                    rowCount[i]++;
                    colCount[j]++;
                }
            }
        }
        
        int specialPositions = 0;
        
        // Second pass: Identify special positions
        for (int i = 0; i < m; ++i) {
            // Optimization: If a row doesn't have exactly one '1', skip it
            if (rowCount[i] != 1) continue;
            
            for (int j = 0; j < n; ++j) {
                if (mat[i][j] == 1 && colCount[j] == 1) {
                    specialPositions++;
                }
            }
        }
        
        return specialPositions;
    }
};
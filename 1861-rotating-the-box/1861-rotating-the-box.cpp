class Solution {
public:
    vector<vector<char>> rotateTheBox(vector<vector<char>>& boxGrid) {
        int m = boxGrid.size();
        int n = boxGrid[0].size();

        // 1. Process Gravity horizontally for each row
        for (int i = 0; i < m; ++i) {
            int lowestAvailable = n - 1; 
            for (int j = n - 1; j >= 0; --j) {
                if (boxGrid[i][j] == '#') {
                    // Move the stone to the lowest available spot
                    boxGrid[i][j] = '.';
                    boxGrid[i][lowestAvailable] = '#';
                    lowestAvailable--;
                } else if (boxGrid[i][j] == '*') {
                    // Obstacle acts as a new floor for stones above it
                    lowestAvailable = j - 1;
                }
            }
        }

        // 2. Rotate the box 90 degrees clockwise
        // Original (r, c) maps to New (c, m - 1 - r)
        vector<vector<char>> result(n, vector<char>(m));
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                result[j][m - 1 - i] = boxGrid[i][j];
            }
        }

        return result;
    }
};
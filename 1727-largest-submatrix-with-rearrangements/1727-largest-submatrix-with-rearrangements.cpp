class Solution {
public:
    int largestSubmatrix(vector<vector<int>>& matrix) {
        int m = matrix.size();
        int n = matrix[0].size();
        int maxArea = 0;

        for (int r = 0; r < m; ++r) {
            for (int c = 0; c < n; ++c) {
                // If current cell is 1, accumulate height from above
                if (matrix[r][c] != 0 && r > 0) {
                    matrix[r][c] += matrix[r - 1][c];
                }
            }

            // We need a copy of the row to sort it without 
            // breaking the height calculations for the next row.
            std::vector<int> currRow = matrix[r];
            std::sort(currRow.begin(), currRow.end(), std::greater<int>());

            // Calculate max area for the current row's heights
            for (int i = 0; i < n; ++i) {
                int height = currRow[i];
                int width = i + 1;
                maxArea = std::max(maxArea, height * width);
            }
        }

        return maxArea;
    }
};
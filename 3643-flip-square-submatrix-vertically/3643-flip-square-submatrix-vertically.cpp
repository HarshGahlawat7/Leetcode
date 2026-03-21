class Solution {
public:
    vector<vector<int>> reverseSubmatrix(vector<vector<int>>& grid, int x, int y, int k) {
        for (int i = 0; i < k / 2; ++i) {
            int topRow = x + i;
            int bottomRow = x + k - 1 - i;
            
            for (int j = 0; j < k; ++j) {
                int col = y + j;
                swap(grid[topRow][col], grid[bottomRow][col]);
            }
        }
        return grid;
    }
};
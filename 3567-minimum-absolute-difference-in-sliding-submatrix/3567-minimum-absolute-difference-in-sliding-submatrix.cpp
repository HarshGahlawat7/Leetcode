class Solution {
public:
    vector<vector<int>> minAbsDiff(vector<vector<int>>& grid, int k) {
        int m = grid.size();
        int n = grid[0].size();
        
        // Result dimensions: (m - k + 1) x (n - k + 1)
        int res_rows = m - k + 1;
        int res_cols = n - k + 1;
        vector<vector<int>> ans(res_rows, vector<int>(res_cols));

        for (int i = 0; i < res_rows; ++i) {
            for (int j = 0; j < res_cols; ++j) {
                
                // Use a set to store distinct values in sorted order
                set<int> distinct_elements;
                for (int r = i; r < i + k; ++r) {
                    for (int c = j; c < j + k; ++c) {
                        distinct_elements.insert(grid[r][c]);
                    }
                }

                // If fewer than 2 distinct elements exist, the diff is 0
                if (distinct_elements.size() < 2) {
                    ans[i][j] = 0;
                } else {
                    int min_diff = INT_MAX;
                    
                    // Iterate through the sorted set to find the smallest gap
                    auto it = distinct_elements.begin();
                    int prev = *it;
                    ++it;
                    
                    while (it != distinct_elements.end()) {
                        min_diff = min(min_diff, *it - prev);
                        prev = *it;
                        ++it;
                    }
                    ans[i][j] = min_diff;
                }
            }
        }
        
        return ans;
    }
};
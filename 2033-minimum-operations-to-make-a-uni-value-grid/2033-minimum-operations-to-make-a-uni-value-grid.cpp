class Solution {
public:
    int minOperations(vector<vector<int>>& grid, int x) {
        int m = grid.size();
        int n = grid[0].size();
        vector<int> nums;
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                nums.push_back(grid[i][j]);
            }
        }
       
        int remainder = nums[0] % x;
        for (int val : nums) {
            if (val % x != remainder) {
                return -1;
            }
        }
        
        sort(nums.begin(), nums.end());
        
        int median = nums[nums.size() / 2];
        int operations = 0;
        for (int val : nums) {
            operations += abs(val - median) / x;
        }
        
        return operations;
    }
};
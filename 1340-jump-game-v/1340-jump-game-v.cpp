class Solution {
    private:
    int dfs(int i, const std::vector<int>& arr, int d, std::vector<int>& dp) {
        // If already calculated, return the cached result
        if (dp[i] != -1) return dp[i];
        
        int max_steps = 1; // Current index itself counts as 1 visited index
        int n = arr.size();
        
        // 1. Move Right: i + x
        for (int x = 1; x <= d && i + x < n; ++x) {
            if (arr[i] <= arr[i + x]) break; // Cannot jump over or to an element >= arr[i]
            max_steps = std::max(max_steps, 1 + dfs(i + x, arr, d, dp));
        }
        
        // 2. Move Left: i - x
        for (int x = 1; x <= d && i - x >= 0; ++x) {
            if (arr[i] <= arr[i - x]) break; // Cannot jump over or to an element >= arr[i]
            max_steps = std::max(max_steps, 1 + dfs(i - x, arr, d, dp));
        }
        
        return dp[i] = max_steps;
    }
public:
    int maxJumps(vector<int>& arr, int d) {
        int n = arr.size();
        std::vector<int> dp(n, -1);
        int ans = 0;
        
        // Try starting from every possible index and find the global maximum
        for (int i = 0; i < n; ++i) {
            ans = std::max(ans, dfs(i, arr, d, dp));
        }
        
        return ans;
    }
};
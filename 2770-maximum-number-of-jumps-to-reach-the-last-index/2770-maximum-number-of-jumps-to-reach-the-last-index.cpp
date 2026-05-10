class Solution {
public:
    int maximumJumps(vector<int>& nums, int target) {
        int n = nums.size();
        // Initialize dp array with -1 to represent unreachable indices
        std::vector<int> dp(n, -1);
        dp[0] = 0;

        for (int j = 1; j < n; ++j) {
            for (int i = 0; i < j; ++i) {
                // Check if the previous index i is reachable
                if (dp[i] != -1) {
                    // Use long long for the difference to prevent potential overflow
                    long long diff = (long long)nums[j] - nums[i];
                    
                    if (diff >= -target && diff <= target) {
                        dp[j] = std::max(dp[j], dp[i] + 1);
                    }
                }
            }
        }
        
        return dp[n - 1];
    }
};
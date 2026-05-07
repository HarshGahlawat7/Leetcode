class Solution {
public:
    vector<int> maxValue(vector<int>& nums) {
        int n = nums.size();
        if (n == 0) return {};
        
        // Step 1: Compute Prefix Maximums
        vector<int> prefMax(n);
        prefMax[0] = nums[0];
        for (int i = 1; i < n; ++i) {
            prefMax[i] = max(prefMax[i - 1], nums[i]);
        }
        
        // Step 2: Compute Suffix Minimums
        vector<int> suffMin(n);
        suffMin[n - 1] = nums[n - 1];
        for (int i = n - 2; i >= 0; --i) {
            suffMin[i] = min(suffMin[i + 1], nums[i]);
        }
        
        vector<int> ans(n);
        int start = 0;
        
        // Step 3: Identify components and fill the result
        for (int i = 0; i < n; ++i) {
            // A component ends at i if the max of the left part 
            // is <= the min of the remaining right part.
            if (i == n - 1 || prefMax[i] <= suffMin[i + 1]) {
                // The maximum reachable value for everyone in [start, i]
                // is the maximum value within this contiguous block.
                int componentMax = prefMax[i];
                for (int k = start; k <= i; ++k) {
                    ans[k] = componentMax;
                }
                start = i + 1; // Move to the next component
            }
        }
        
        return ans;
    }
};
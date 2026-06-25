class Solution {
public:
    int countMajoritySubarrays(vector<int>& nums, int target) {
        int n = nums.size();
        int total_subarrays = 0;
        
        // Iterate through all possible starting positions of the subarrays
        for (int i = 0; i < n; ++i) {
            int current_balance = 0;
            
            // Expand the subarray window to the right
            for (int j = i; j < n; ++j) {
                if (nums[j] == target) {
                    current_balance += 1;
                } else {
                    current_balance -= 1;
                }
                
                // If balance > 0, the target is strictly the majority element
                if (current_balance > 0) {
                    total_subarrays += 1;
                }
            }
        }
        
        return total_subarrays;
    }
};
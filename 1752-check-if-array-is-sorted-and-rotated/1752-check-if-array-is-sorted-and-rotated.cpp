class Solution {
public:
    bool check(vector<int>& nums) {
        int count_drops = 0;
        int n = nums.size();
        
        for (int i = 0; i < n; ++i) {
            // Using (i + 1) % n seamlessly checks the last element against the first one
            if (nums[i] > nums[(i + 1) % n]) {
                count_drops++;
            }
            
            // Optimization: Break early if we find more than 1 drop
            if (count_drops > 1) {
                return false;
            }
        }
        
        return true;
    }
};
class Solution {
public:
    int singleNonDuplicate(vector<int>& nums) {
        int left = 0, right = nums.size() - 1;
        
        while (left < right) {
            int mid = left + (right - left) / 2;
            
            // Ensure mid is even
            if (mid % 2 == 1) {
                mid--;
            }
            
            // Check if the single element is on the right or left
            if (nums[mid] == nums[mid + 1]) {
                left = mid + 2; // Single element is on the right
            } else {
                right = mid; // Single element is on the left
            }
        }
        
        return nums[left];
    }
};
class Solution {
public:
    int search(vector<int>& nums, int target) {
        int low = 0;
        int high = nums.size() - 1;
        
        while (low <= high) {
            int mid = low + (high - low) / 2;
            
            // If target is found, return its index
            if (nums[mid] == target) {
                return mid;
            }
            
            // Check if the left half is sorted
            if (nums[low] <= nums[mid]) {
                // Check if the target lies within the sorted left half
                if (target >= nums[low] && target < nums[mid]) {
                    high = mid - 1; // Narrow down to the left half
                } else {
                    low = mid + 1;  // Otherwise, search the right half
                }
            } 
            // Otherwise, the right half must be sorted
            else {
                // Check if the target lies within the sorted right half
                if (target > nums[mid] && target <= nums[high]) {
                    low = mid + 1;  // Narrow down to the right half
                } else {
                    high = mid - 1; // Otherwise, search the left half
                }
            }
        }
        
        // Target not found
        return -1;
    }
};
class Solution {
public:
    bool search(vector<int>& nums, int target) {
        int left = 0, right = nums.size() - 1;
        
        while (left <= right) {
            int mid = left + (right - left) / 2;
            
            if (nums[mid] == target) return true;

            // Handle duplicates: If left, mid, and right are the same, skip duplicates
            if (nums[left] == nums[mid] && nums[mid] == nums[right]) {
                left++;
                right--;
                continue;
            }

            // Left half is sorted
            if (nums[left] <= nums[mid]) {
                if (nums[left] <= target && target < nums[mid])
                    right = mid - 1;  // Search left
                else
                    left = mid + 1;   // Search right
            }
            // Right half is sorted
            else {
                if (nums[mid] < target && target <= nums[right])
                    left = mid + 1;   // Search right
                else
                    right = mid - 1;  // Search left
            }
        }
        return false;
    }
};

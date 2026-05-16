class Solution {
public:
    int findMin(vector<int>& nums) {
        int low = 0;
        int high = nums.size() - 1;
        
        while (low < high) {
            int pivot = low + (high - low) / 2;
            
            // Case 1: The minimum is in the left half (including pivot)
            if (nums[pivot] < nums[high]) {
                high = pivot;
            }
            // Case 2: The minimum is in the right half (excluding pivot)
            else if (nums[pivot] > nums[high]) {
                low = pivot + 1;
            }
            // Case 3: Duplicates encountered.
            // nums[pivot] == nums[high], so we safely shrink the search space.
            else {
                high--;
            }
        }
        
        return nums[low];
    }
};
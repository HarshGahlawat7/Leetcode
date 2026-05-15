class Solution {
public:
    int findMin(vector<int>& nums) {
        int left = 0;
        int right = nums.size() - 1;

        // Standard Binary Search approach
        while (left < right) {
            // Using this formula instead of (left + right) / 2 to prevent potential overflow
            int mid = left + (right - left) / 2;

            if (nums[mid] > nums[right]) {
                // The minimum is in the right half, mid cannot be the minimum
                left = mid + 1;
            } else {
                // The minimum is either mid or in the left half
                right = mid;
            }
        }

        // After the loop, left == right, pointing to the minimum element
        return nums[left];
    }
};
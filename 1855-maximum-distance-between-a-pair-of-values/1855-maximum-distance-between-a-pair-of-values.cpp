class Solution {
public:
    int maxDistance(vector<int>& nums1, vector<int>& nums2) {
        int i = 0;
        int j = 0;
        int maxDist = 0;
        int n = nums1.size();
        int m = nums2.size();

        while (i < n && j < m) {
            // Check if the current pair (i, j) is valid
            if (nums1[i] <= nums2[j]) {
                // Update max distance (j - i)
                maxDist = max(maxDist, j - i);
                // Try to find a larger j for the current i
                j++;
            } else {
                // nums1[i] is too large for the current nums2[j],
                // so we must move i to a smaller value.
                i++;
            }
        }

        return maxDist;
    }
};
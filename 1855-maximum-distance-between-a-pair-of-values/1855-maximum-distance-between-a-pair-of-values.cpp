class Solution {
public:
    int maxDistance(vector<int>& nums1, vector<int>& nums2) {
        int i = 0;
        int j = 0;
        int maxDist = 0;
        int n = nums1.size();
        int m = nums2.size();

        while (i < n && j < m) {
            if (nums1[i] <= nums2[j]) {
                maxDist = max(maxDist, j - i);
                j++;
            } else {
                i++;
            }
        }

        return maxDist;
    }
};
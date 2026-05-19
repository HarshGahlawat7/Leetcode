class Solution {
public:
    int getCommon(vector<int>& nums1, vector<int>& nums2) {
        int i = 0;
        int j = 0;
        int len1 = nums1.size();
        int len2 = nums2.size();
        
        // Traverse both arrays until one pointer runs out of bounds
        while (i < len1 && j < len2) {
            if (nums1[i] == nums2[j]) {
                return nums1[i]; // Found the smallest common element
            } 
            else if (nums1[i] < nums2[j]) {
                i++; // Move the pointer in nums1 forward
            } 
            else {
                j++; // Move the pointer in nums2 forward
            }
        }
        
        return -1;
    }
};
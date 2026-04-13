class Solution {
public:
    int getMinDistance(vector<int>& nums, int target, int start) {
        int minDistance = nums.size(); 

        for (int i = 0; i < nums.size(); ++i) {
            if (nums[i] == target) {
                int currentDistance = std::abs(i - start);
                if (currentDistance < minDistance) {
                    minDistance = currentDistance;
                }
                if (minDistance == 0) return 0;
            }
        }
        
        return minDistance;
    }
};
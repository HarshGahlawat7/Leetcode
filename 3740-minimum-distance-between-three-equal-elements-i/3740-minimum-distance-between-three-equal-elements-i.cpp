class Solution {
public:
    int minimumDistance(vector<int>& nums) {
        int n = nums.size();
        // Map to store the indices of each unique number
        unordered_map<int, vector<int>> indexMap;
        
        for (int i = 0; i < n; ++i) {
            indexMap[nums[i]].push_back(i);
        }
        
        int min_dist = INT_MAX;
        bool found = false;
        
        for (auto const& [val, indices] : indexMap) {
            // A good tuple requires at least 3 occurrences
            if (indices.size() >= 3) {
                found = true;
                // Check every set of 3 consecutive indices
                for (int m = 0; m <= (int)indices.size() - 3; ++m) {
                    int i = indices[m];
                    int k = indices[m + 2];
                    // Distance is 2 * (k - i)
                    int current_dist = 2 * (k - i);
                    min_dist = min(min_dist, current_dist);
                }
            }
        }
        
        return found ? min_dist : -1;
    }
};
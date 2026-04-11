class Solution {
public:
    int minimumDistance(vector<int>& nums) {
        unordered_map<int, vector<int>> indexMap;
        int n = nums.size();
        
        // Step 1: Group indices by value
        for (int i = 0; i < n; i++) {
            indexMap[nums[i]].push_back(i);
        }
        
        long long min_dist = LLONG_MAX;
        bool found = false;
        
        // Step 2: Check each group of indices
        for (auto const& [val, indices] : indexMap) {
            if (indices.size() >= 3) {
                found = true;
                // Sliding window of size 3 over the indices
                for (int t = 0; t <= (int)indices.size() - 3; t++) {
                    // Distance = 2 * (max_index - min_index)
                    long long current_dist = 2LL * (indices[t + 2] - indices[t]);
                    if (current_dist < min_dist) {
                        min_dist = current_dist;
                    }
                }
            }
        }
        
        return found ? (int)min_dist : -1;
    }
};
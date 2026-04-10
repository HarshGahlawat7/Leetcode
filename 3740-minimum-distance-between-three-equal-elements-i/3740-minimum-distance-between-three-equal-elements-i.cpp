class Solution {
public:
    int minimumDistance(vector<int>& nums) {
        int n = nums.size();
        unordered_map<int, vector<int>> indexMap;
        
        for (int i = 0; i < n; ++i) {
            indexMap[nums[i]].push_back(i);
        }
        
        int min_dist = INT_MAX;
        bool found = false;
        
        for (auto const& [val, indices] : indexMap) {
            if (indices.size() >= 3) {
                found = true;
                for (int m = 0; m <= (int)indices.size() - 3; ++m) {
                    int i = indices[m];
                    int k = indices[m + 2];
                    int current_dist = 2 * (k - i);
                    min_dist = min(min_dist, current_dist);
                }
            }
        }
        
        return found ? min_dist : -1;
    }
};